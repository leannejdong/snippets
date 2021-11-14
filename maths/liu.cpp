#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include <cmath>
#include <cstdlib>

#include <Eigen/Dense>

using std::abs;

constexpr double K1{0.0179};
constexpr double K3{0.0269};

void newton3d(Eigen::VectorXd& m,
              double tolerance,
              std::function<Eigen::VectorXd(const Eigen::VectorXd&)> F,
              std::function<Eigen::MatrixXd(const Eigen::VectorXd&)> DF
              )

{
	Eigen::VectorXd m_prev, s;
	
    std::vector<double> errors;
	errors.push_back((F(m)).norm());
	do	{
        m_prev = m;
		s = DF(m).lu().solve(F(m));
	  	m = m-s; // newton iteration
	} while (s.norm() > tolerance*m.norm());
}

int main()
{
    // F
    auto F = [](const Eigen::VectorXd &m){ 
   		Eigen::VectorXd res(3);
        res << m(0)-m(1)-2, 
        m(1)+m(2)-3, 
        K1 * (m(0) * abs(m(0)) + m(1) * abs(m(1))) - K3 * m(2) * abs(m(2));
        return res;
	};
	// jacobian of F
	auto DF= [] (const Eigen::VectorXd &m){
    	Eigen::MatrixXd J(3,3);
		J << 1, -1, 0,
		  	 0, 1, 1,
            2 * K1 * abs(m(0)) ,  2 * K1 * abs(m(1)),  -2 * K3 * abs(m(2));
	  	return J;
	};	

    Eigen::VectorXd m(3);
	m << 1.0, 1.0, 1.0; // initial value
    double tolerance = 1e-14;
	newton3d(m, tolerance, F, DF);
    
    std::cout << std::setprecision(17) << "solution = " << m << "\n";
    std::cout << std::setprecision(17) << "error norm = " << F(m).norm() << "\n";
}
