#include "stdafx.h"
#include "Circle.h"
using namespace std;

Circle::Circle(void)
{
	rad=1;
}


Circle::~Circle(void)
{
}
double Circle::Lice()
{
	return 3.14*rad*rad;
}
double Circle::Perim()
{
	return 2*rad*3.14;
}
