#pragma once
#include "triange.h"

class Prism:public Triange
{
	double h;
public:
	Prism(void);
	~Prism(void);
	void setA(double A) { Triange::setA(A); }
	double getA() { return Triange::getA(); }

	void setB(double B) { Triange::setB(B); }
	double getB() { return Triange::getB(); }

	void setC(double C) { Triange::setC(C); }
	double getC() { return Triange::getC(); }

	void setH(double H) { h = H;}
	double getH() { return h; }

	double CalcV() { return Triange::Lice()*h;}
	double CalcS() { return Triange::Lice()*2 + Triange::Perim()*h ;}

	friend std::ostream& operator<<(std::ostream &os, Prism &f)
	{

		cout << "A = " ; os << f.getA() << endl;
		cout << "B = " ; os << f.getB() << endl;
		cout << "C = " ; os << f.getC() << endl;
		cout << "h = " ; os << f.getH() << endl;
		return os;
	}
	friend std::istream &operator>>(std::istream &in, Prism &f) 
	{
		double V;
		cout << "A = " ;in >> V;  f.setA(V); 
		cout << "B = " ;in >> V;  f.setB(V);
		cout << "C = " ;in >> V;  f.setC(V);
		cout << "h = " ;in >> V;  f.setH(V); 
		return in;
	}

};

