#include <random>
#include <algorithm>
#include <set>
#include <iostream>
#include <thread>
#include <future>
#include <cassert>
std::set<int> make_sorted_random(const size_t num_elems)
{
    std::set<int> retval;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, num_elems-1);
    std::generate_n(std::inserter(retval, retval.end()), num_elems, [&](){ return dis(gen); });
    throw std::runtime_error("Hi there");
    return retval;

}

/*
template< class OutputIt, class Size, class Generator >
constexpr // since C++20
OutputIt  // void until C++11
generate_n( OutputIt first, Size count, Generator g )
{
    for( Size i = 0; i < count; ++i ) {
        *first++ = g();
    }
    return first;
}
*/

int main()
{
  auto f1 = std::async(std::launch::async, make_sorted_random, 1000000);// here we call make_sorted_random asynchronously, it returns a future. The future holds a value that is promised to 
  // exist in the future
  auto f2 = std::async(std::launch::async, make_sorted_random, 1000000);
  auto f3 = std::async(std::launch::async, make_sorted_random, 1000000); 
  auto f4 = std::async(std::launch::async, make_sorted_random, 1000000); 
  auto f5 = std::async(std::launch::async, make_sorted_random, 1000000); 
  auto f6 = std::async(std::launch::async, make_sorted_random, 1000000); 
  auto f7 = std::async(std::launch::async, make_sorted_random, 1000000); 
  auto f8 = std::async(std::launch::async, make_sorted_random, 1000000);

//  try{
//    f1.get();
//  }catch (const std::exception &e){
//    std::cerr << "f1 threw exception: " << e.what() << "\n";
//  }
  std::cout << f1.get().size() << ' ' << f2.get().size() << ' ' << f3.get().size() << ' '<< f4.get().size() << ' '
    << f5.get().size()<< ' ' << f6.get().size() << ' '<< f7.get().size() << ' '<< f8.get().size()<<"\n";



//  std::cout << std::async(make_sorted_random,1000000).get().size()<<' '<< std::async(make_sorted_random,1000000).get().size()<<
//    ' '<<std::async(make_sorted_random,1000000).get().size()<<' '<<std::async(make_sorted_random,1000000).get().size()<< 
//    ' '<<std::async(make_sorted_random,1000000).get().size()<<' '<< std::async(make_sorted_random,1000000).get().size()<<' '
//    << std::async(make_sorted_random,1000000).get().size()<<' '<<std::async(make_sorted_random,1000000).get().size()<<"\n";
}
/*
 * 632309 631643 632067 632518 631893 632791 631930 632512
21.44user 26.08system 0:07.23elapsed 657%CPU (0avgtext+0avgdata 240924maxresident)k
0inputs+0outputs (0major+59461minor)pagefaults 0swaps
*/
