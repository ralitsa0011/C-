// accumulate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double sum (double a, double b) { return a + b; }
double accumulate(double arr[], int size, double (*pfn)(double,double), double start)
{
	double s = start;
	for(int i = 0; i < size; i++) 
		s = pfn(s,arr[i]);
	return s;
}
int main()
{
	double arr[10] = {3,11,10,7,20,19,35,40,27,30};
	double s = accumulate(arr,10,sum,10);
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << "sum = " << s << endl;
	return 0;
}

