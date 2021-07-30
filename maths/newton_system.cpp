#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <cassert>
#include <memory>
#include <iostream>

#include <Eigen/Dense>
using std::cerr;
using Eigen::VectorXd;
using Eigen::MatrixXd;

constexpr double K1{0.0179};
constexpr double K3{0.0269};

class Iteration{
public:
    virtual VectorXd solve(Eigen::VectorXd&) { return {}; }

    int numberOfIterations() const { return mNumberOfIterations; }
    virtual ~Iteration() = default;

protected:
    explicit Iteration(double epsilon) : mEpsilon(epsilon), mNumberOfIterations(0) {}

    void resetNumberOfIterations() { mNumberOfIterations = 0; }
    int incrementNumberOfIterations() { return mNumberOfIterations++; }
    double epsilon() const { return mEpsilon; }

private:
    const double mEpsilon;
    int mNumberOfIterations;    
};

class Newton : public Iteration{
    public:
  //  Newton(double epsilon, const std::function<double (double)> f, const std::function<double (double)> fPrime) : Iteration(epsilon), mf(f), mfPrime(fPrime) {}
    
    ~Newton() override = default;

    Newton(Eigen::VectorXd& m,
              double tolerance,
              std::function<Eigen::VectorXd(const Eigen::VectorXd&)> F,
              std::function<Eigen::MatrixXd(const Eigen::VectorXd&)> DF
    ): Iteration(tolerance), _F(F), _DF(DF){}

    VectorXd solve(Eigen::VectorXd&x) override {
        resetNumberOfIterations();
     
        VectorXd Fx = _F(x);
        MatrixXd DF = _DF(x);
   
        calculateX(x, epsilon(), _F, _DF );
        return x;
    }
    private:
    static void calculateX(VectorXd& x, double tolerance,
              std::function<Eigen::VectorXd(const Eigen::VectorXd&)> F,
              std::function<Eigen::MatrixXd(const Eigen::VectorXd&)> DF) {
                  Eigen::VectorXd x_prev, s;
                  std::vector<double> errors;
                  errors.push_back((F(x)).norm());
                  do{
                      x_prev = x;
                      s = DF(x).lu().solve(F(x));
                      x = x - s; 
                     // fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n",incrementNumberOfIterations(), x, F, DF);
                  } while (s.norm() > tolerance *x.norm());
                
    }
    std::function<Eigen::VectorXd(const Eigen::VectorXd&)> _F;
    std::function<Eigen::MatrixXd(const Eigen::VectorXd&)> _DF;

};

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
    const double tolerance = 1e-14;
    std::unique_ptr<Iteration> newton = std::make_unique<Newton>(m, tolerance, F, DF);
    VectorXd newtonResults = newton->solve(m);

    
     std::cout << std::setprecision(17) << "solution = " << newtonResults << "\n";
     std::cout << std::setprecision(17) << "error norm = " << F(m).norm() << "\n";


}
