//#include <boost/timer/timer.hpp>
#include <unsupported/Eigen/CXX11/Tensor>
#include <iostream>
#include <chrono>

using std::cerr;


int main()
{
    const int n = 100;
    Eigen::Tensor<double, 3> T(n, n, n);
    Eigen::Tensor<double, 1> y(n), z(n);
    int ii = 1;
    for (int i = 0; i < n; ++i) {
        y(i) = i+1;
        z(i) = i + 3;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                T(i, j, k) = ++ii;
            }
        }
    }
    //cerr << T << "\n";
    typedef Eigen::IndexPair<int> IP;
    Eigen::array<IP, 1> d10 = { IP(1, 0) }; // second index of T
    auto start = std::chrono::steady_clock::now();
    Eigen::Tensor<double, 1>  Tyz = T.contract(y, d10).contract(z, d10);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_secs = end - start;
    //cerr << Tyz << "\n";
    //boost::chrono::duration<double> elapsed = boost::chrono::nanoseconds(timer.elapsed().user);

    printf("elapsed time=%8.3f\n", elapsed_secs.count());

//   // brute force
    Eigen::VectorXd v(n);
    v.setZero();
    auto start1 = std::chrono::steady_clock::now();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                v(i) += T(i,j,k)*y(j)*z(k);
            }
        }
    }
    // cerr << v.transpose() << "\n";
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_secss = end1 - start1;

    printf("elapsed time=%8.3f\n", elapsed_secss.count());
}

// https://godbolt.org/z/YK8bba

