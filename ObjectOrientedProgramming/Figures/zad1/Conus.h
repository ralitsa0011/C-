#pragma once
#include "triange.h"
#include "circle.h"
class Conus :
	public Triange, Circle
{
public:
	Conus(void);
	~Conus(void);
	void setA(double A) { Triange::setA(A); }
	double getA() { return Triange::getA(); }

	void setB(double B) { Triange::setB(B); }
	double getB() { return Triange::getB(); }

	void setD(double D) { Circle::setR(D/2); Triange::setC(D); }
	double getD() { return Circle::getR()*2; }

	double CalcV() {return Circle::Lice()*H()/3;}
	double CalcS() { 
		return Circle::Lice() + Circle::Perim()*sqrt(H()*H()+Circle::getR()* Circle::getR());}

	double H() { return Triange::Lice()*2/ Triange::getC();}\

	friend std::ostream& operator<<(std::ostream &os, Conus&f)
	{
		os <<f.getA()<<endl;
		os<< f.getB()<<endl;
		os<<f.getD()<<endl;
		return os;
	}
	friend std::istream &operator>>(std::istream &in, Conus &f) 
	{
		double V;
		in >> V;  f.setA(V); 
		in >> V;  f.setB(V); 
		in >> V;  f.setD(V); 
		return in;
	}
};

