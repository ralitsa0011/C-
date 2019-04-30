#pragma once
#include <iostream>
using namespace std;
class Triange
{
	double a,b,c;
public:
	Triange(void);
	~Triange(void);
	double getA(){return a;}
	void setA(double nA){a=nA;}
	double getB(){return b;}
	void setB(double nB){b=nB;}
	double getC(){return c;}
	void setC(double nC){c=nC;}
	double Lice();
	double Perim();
	friend std::ostream& operator<<(std::ostream &os, Triange &f)
	{
		os <<f.getA()<<endl;
		os<< f.getB()<<endl;
		os<<f.getC()<<endl;
		return os;
	}
	friend std::istream &operator>>(std::istream &in, Triange &f) 
	{
		double V;
		in >> V;  f.setA(V); 
		in >> V;  f.setB(V); 
		in >> V;  f.setC(V); 
		return in;
	}
};

