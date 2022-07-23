
#include "solver.hpp"
#include <iostream>
#include <complex>

using namespace std;

namespace solver {

RealVariable operator == (RealVariable A, RealVariable B){
        RealVariable C = A - B;
        return C;
    }
 RealVariable operator*(RealVariable A, RealVariable B){
 RealVariable C;
 C.x_2=A.x_0*B.x_2 + A.x_2*B.x_0 + A.x_1*B.x_1; 
 C.x_1=(A.x_1*B.x_0) + (A.x_0*B.x_1);
 C.x_0=A.x_0*B.x_0;
 return C;
 }
     RealVariable operator-(RealVariable A, RealVariable B){
         RealVariable C;
         C.x_2=A.x_2 - B.x_2;
         C.x_1= A.x_1 - B.x_1;
         C.x_0=A.x_0 - B.x_0;
         return C; 
     }
     RealVariable operator + (RealVariable A, RealVariable B){
        RealVariable C;
        C.x_2=A.x_2 + B.x_2;
        C.x_1=A.x_1 + B.x_1;
        C.x_0=A.x_0 + B.x_0;
        return C;
    }
     RealVariable operator/(RealVariable A, RealVariable B){
     RealVariable C;
	    C.x_2=A.x_2 / B.x_2;
	    C.x_1=A.x_1 / B.x_1;
        C.x_0=A.x_0 / B.x_0;
	    return C;
     }
    RealVariable operator^(RealVariable A, RealVariable B){
     if(B.x_0 != 2){
         throw std::invalid_argument("Power must be 2");
      }
        RealVariable C;
        C.x_2 = 1.0;
        C.x_1 = 0;
        C.x_0 = 0;
        
        return C;
    }
     double solve(RealVariable A){
      double x2 = A.getx_2();
      double x1 = A.getx_1();
      double x0 = A.getx_0();
      double ans;
      if(x2 == 0.0 && x1 == 0.0)
        throw std::runtime_error("No solution to the real numbers");
      else if(x2 == 0.0)
        ans = -x0/x1;
      else{
          double temp= x1*x1 - 4.0*x2*x0;
          if(temp>=0){
          ans= -x1+ std::sqrt(temp);
          ans=ans/(2.0*x2);
          }
        else
        throw std::runtime_error("No solution to the real numbers");
      }
       return ans;
     }

     ComplexVariable operator+(ComplexVariable A, ComplexVariable B){
     ComplexVariable C;
        C.x_2 = A.x_2 + B.x_2;
        C.x_1 = A.x_1 + B.x_1;
        C.x_0 = A.x_0 + B.x_0;
        return C;
     }
     ComplexVariable operator*(ComplexVariable A, ComplexVariable B){
         ComplexVariable C;
        C.x_2=A.x_0*B.x_2 + A.x_2*B.x_0 + A.x_1*B.x_1; 
        C.x_1=(A.x_1*B.x_0) + (A.x_0*B.x_1);
        C.x_0=A.x_0*B.x_0;
        return C;
     }
     ComplexVariable operator==(ComplexVariable A, ComplexVariable B){
         ComplexVariable C = A - B;
        return C;
     }
     ComplexVariable operator-(ComplexVariable A, ComplexVariable B){
        ComplexVariable C;
         C.x_2=A.x_2 - B.x_2;
         C.x_1= A.x_1 - B.x_1;
         C.x_0=A.x_0 - B.x_0;
        return C;
     }
     ComplexVariable operator/(ComplexVariable A, ComplexVariable B){
        ComplexVariable C;
	    C.x_2=A.x_2 / B.x_2;
	    C.x_1=A.x_1 / B.x_1;
        C.x_0=A.x_0 / B.x_0;
	    return C;
     }
     ComplexVariable operator ^ (ComplexVariable A, ComplexVariable B){
      if(B.x_0.real() != 2){
         throw std::invalid_argument("Power must be 2");
      }
        ComplexVariable C;
        C.x_0 = 0;
        C.x_1 = 0;
        C.x_2 = 1.0;
        return C;
    }
     std::complex<double> solve(ComplexVariable A){
      std::complex<double> x2 = A.getx_2();
      std::complex<double> x1 = A.getx_1();
      std::complex<double> x0 = A.getx_0();
      std::complex<double> ans;

      if(x2.real() == 0.0 && x1.real() == 0.0 && x2.imag() == 0.0 && x1.imag() == 0.0)
        throw std::runtime_error("No solution to the real numbers");
      else if(x2.real() == 0.0 && x2.imag() == 0.0)
        ans = -x0/x1;
     else {
          std::complex<double> temp= x1*x1 -4.0*x2*x0;
          ans= -x1 + std::sqrt(temp);
          ans=ans/(2.0*x2);
          }
         
       return ans;
    }
}

   
           

   

