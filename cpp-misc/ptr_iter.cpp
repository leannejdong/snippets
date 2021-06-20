#include <numeric>
#include <iostream>
#include <vector>


int main()
{
    // int a, *b;
    // a = 3;
    // b = &a;
    // std::cerr << *b << "\n";

    // a = 4;
    // std::cerr << *b << "\n";

    std::vector<double> vec1(2, 3.1), *vec2;
    vec2 = &vec1;

  //  std::cerr << vec1.size() << " " << vec2->size()<< "\n";
    for (auto v : *vec2){
        std::cerr << v << "\n";
    }

    std::cerr << "Let's now play the game of iterators\n";


    std::vector<double> vec(2, 3.1);

    // for(std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it){
    //     std::cerr << *it << "\n";
    // }
    for (auto v : vec){
        std::cerr << v << "\n";
    }

}
//https://godbolt.org/z/adbnhhT7b
