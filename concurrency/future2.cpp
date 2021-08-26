
#include <random>
#include <algorithm>
#include <set>
#include <iostream>
#include <future>

std::set<int> make_sorted_random(const size_t num_elems)
{
    std::set<int> retval;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, num_elems-1);
    std::generate_n(std::inserter(retval, retval.end()), num_elems, [&](){ return dis(gen); });
    return retval;

}

int main()
{ /*
     leanne@tensorbook:~/Dev/snippets/concurrency$ /usr/bin/time ./future2
     632444 632565 632060
     4.17user 0.25system 0:02.91elapsed 151%CPU (0avgtext+0avgdata 92800maxresident)k
     0inputs+0outputs (0major+22389minor)pagefaults 0swaps

  */
  auto f1 = std::async(std::launch::async, make_sorted_random, 1000000);
  auto f2 = std::async(std::launch::async, make_sorted_random, 1000000);
  auto f3 = std::async(std::launch::deferred, make_sorted_random, 1000000);// save us effort if the computer got insufficient core
  //auto f4 = std::async(std::launch::deferred, make_sorted_random, 1000000);// deferred means lazy evaluation, it only got evaluated when it is called
  //auto f5 = std::async(std::launch::deferred, make_sorted_random, 1000000);
  std::cout << f1.get().size() << ' ' << f2.get().size() << ' ' << f3.get().size() <<'\n';

  ////std::cout << f3.get().size() << ' ' << f4.get().size() << ' ' << f5.get().size() << "\n";
  //  std::cout << std::async(make_sorted_random, 1000000).get().size() << ' ' << std::async(make_sorted_random, 1000000).get().size() << "\n";

}
/*  
  std::cout << std::async(make_sorted_random, 1000000).get().size() << ' ' << std::async(make_sorted_random, 1000000).get().size() << "\n";
 *$ /usr/bin/time ./future2
632106 631810
2.24user 0.03system 0:02.28elapsed 99%CPU (0avgtext+0avgdata 63088maxresident)k
0inputs+0outputs (0major+14961minor)pagefaults 0swaps
Here we are using only 1 core even we were expecting it to use the available cores.
std::async can choose to run in the background asynchronously or in a deferred manner
 */
