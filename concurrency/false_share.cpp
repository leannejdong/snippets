/* this program show several implications of false sharing
 * in C++ using std::atomic and std::thread */

#include <thread>
#include <atomic>
#include <iostream>

using std::thread;
using std::atomic;
using std::cerr;

// incrementing an atomic int
void work(atomic<int>& a){
  for(int i = 0; i < 10000; ++i){
    a++;
  }
}

// single-threaded function that calls work 4 times
void single_thread(){
  atomic<int> a;
  a = 0;

  work(a);
  work(a);
  work(a);
  work(a);
}

// Tries to parallelize the work across multiple threads
// However, each core invalidates the other cores copies on a write
// This is a poorly thoughtout code
void same_var(){
  atomic<int> a;
  a = 0;
  // Create 4 threads and use a lambda to launch work
  thread t1([&](){ work(a); });
  thread t2([&](){ work(a); });
  thread t3([&](){ work(a); });
  thread t4([&](){ work(a); }); 

  // Join the threads
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

void diff_var(){
  atomic<int> a{0};
  atomic<int> b{0};
  atomic<int> c{0};
  atomic<int> d{0};
  // Create 4 threads and use a lambda to launch work
  thread t1([&](){ work(a); });
  thread t2([&](){ work(b); });
  thread t3([&](){ work(c); });
  thread t4([&](){ work(d); }); 

  // Join the threads
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}
struct alignas(64) AlignedType {
  AlignedType() { val = 0; }
  std::atomic<int> val;
};

// No more invalidations, so our code should be roughly the same as the
void diff_line() {
 // AlignedType a{};
 // AlignedType b{};
 // AlignedType c{};
 // AlignedType d{};
  AlignedType a; a.val =0;
  cerr << "Address of a :" << &a << "\n";

  AlignedType b; b.val =0;
  cerr << "Address of b :" << &b << "\n";

  AlignedType c; c.val =0;
  cerr << "Address of c :" << &c << "\n";

  AlignedType d; d.val =0;
  cerr << "Address of d :" << &d << "\n";

  // Launch the four threads now using our aligned data
  thread t1([&]() { work(a.val); });
  thread t2([&]() { work(b.val); });
  thread t3([&]() { work(c.val); });
  thread t4([&]() { work(d.val); });

  // Join the threads
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

int main()
{
//  single_thread();
//  same_var();
  diff_var();
  diff_line();
  return 0;
}
