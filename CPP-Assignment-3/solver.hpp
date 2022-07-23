
# pragma once
#include <iostream>
#include <complex>
using namespace std;

namespace solver{

    class RealVariable{

        double x_2=0.0;
        double x_1=1.0;
        double x_0=0.0;

    public:

        RealVariable(){}
	    RealVariable(double c) : x_2(0), x_1(0), x_0(c) {}
         RealVariable(const RealVariable& other){
             this->x_2=other.x_2;
              this->x_1=other.x_1;
               this->x_0=other.x_0;
         }
        ~RealVariable() {}
		
        double getx_0() {
         return this->x_0;
        }
        double getx_1() {
         return this->x_1;
        }
        double getx_2() {
         return this->x_2;
        }

        friend RealVariable operator==(RealVariable A, RealVariable B);
        friend RealVariable operator*(RealVariable A, RealVariable B);
        friend RealVariable operator-(RealVariable A, RealVariable B);
        friend RealVariable operator+(RealVariable A, RealVariable B);
        friend RealVariable operator/(RealVariable A, RealVariable B);
        friend RealVariable operator^(RealVariable A, RealVariable B);
    };

    class ComplexVariable {

        std::complex<double> x_0=0.0;
        std::complex<double> x_1=1.0;
        std::complex<double> x_2=0.0;
    
    public:

       ComplexVariable(){}
	   ComplexVariable(double c) : x_2(0), x_1(0), x_0(c) {}
       ComplexVariable(std::complex<double> c) : x_2(0), x_1(0), x_0(c) {}

       ~ComplexVariable(){}  
       
       std::complex<double> getx_0() const{
         return this->x_0;
        }
        std::complex<double> getx_1() const{
         return this->x_1;
        }
        std::complex<double> getx_2() const{
         return this->x_2;
        }

        friend  ComplexVariable operator+(ComplexVariable A, ComplexVariable B);
        friend  ComplexVariable operator*(ComplexVariable A, ComplexVariable B);
        friend  ComplexVariable operator==(ComplexVariable A, ComplexVariable B);
        friend  ComplexVariable operator-(ComplexVariable A, ComplexVariable B);
        friend  ComplexVariable operator/(ComplexVariable A, ComplexVariable B);
        friend ComplexVariable operator ^  (ComplexVariable A, ComplexVariable B);
    };
   
        double solve(RealVariable);
        std::complex<double> solve(ComplexVariable);
    }

 
