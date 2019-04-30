#include "stdafx.h"
#include "Triange.h"
#include <math.h>


Triange::Triange(void)
{
	a=1;
	b=1;
	c=1;
}


Triange::~Triange(void)
{
}
double Triange::Lice()
	{
		double p=Perim()/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
double Triange::Perim()
{
	return a+b+c;
}