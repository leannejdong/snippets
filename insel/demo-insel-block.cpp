#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include <cmath>
#include <cstdlib>

#include <Eigen/Dense>

int main();
void newton3d(Eigen::VectorXd& m,
              double tolerance,
              std::function<Eigen::VectorXd(const Eigen::VectorXd&)> F,
              std::function<Eigen::MatrixXd(const Eigen::VectorXd&)> DF);
extern "C" void id (float *in, float *out, int *IP, float *RP, double *DP,
                    float *BP, char SP[][1024], char BNAMES[1024],
                    int *OPM, int *INMIN, int *INS, int *OUTS,
                    int *IPS, int *RPS, int *DPS,
                    int *BPMIN, int *BPS, int *SPMIN,
                    int *SPS, int *GROUP);
extern "C" void ub0013(float *in, float *out, int *IP, float *RP,
   double *DP, float *BP, char SP[][1024])
{

    char BNAMES[1024] = "UBLIU";
    int  OPM   = 1;
    int  INMIN = 0;
    int  INS   = 0;
    int  OUTS  = 1;
    int  IPS   = 10;
    int  RPS   = 0;
    int  DPS   = 0;
    int  BPMIN = 0;
    int  BPS   = 0;
    int  SPMIN = 0;
    int  SPS   = 0;
    int  GROUP = 3;

    if (IP[1] != 0)
    {
        if (IP[1] == -1)
        {
            // Identification call
            // id(in, out, IP, RP, DP, BP, SP, BNAMES,
            //     &OPM, &INMIN, &INS, &OUTS, &IPS, &RPS, &DPS,
            //     &BPMIN, &BPS, &SPMIN, &SPS, &GROUP);
        }
        else if(IP[1] == 1)
        {
            // Constructor call
        }
        else
        {
            // Destructor call
        }
        return;
    }
    // Standard call ----------------------------------------------------

    main();

}

constexpr double K1{0.0179};
constexpr double K3{0.0269};

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
// don't forget to add -I /usr/include/eigen3 from compiling from terminal or makefile
