#pragma once
#include <iostream>
using namespace std;
class Circle
{
	double rad;
public:
	Circle(void);
	~Circle(void);
	void setR(double n) {rad=n;}
	double getR(){return rad;}
	double Lice();
	double Perim();
	friend ostream& operator <<(ostream &os, Circle &f)
	{
		os<<f.getR()<<endl;
		return os;
	}
	friend istream& operator >>(istream &is, Circle &f)
	{
		double V;
		is>>V;
       f.setR(V);
	   return is;
	}
};

