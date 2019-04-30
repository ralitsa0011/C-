// PointersToFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

double Add(double a, double b) {return a+b;}

double Sub(double a, double b) {return a-b;}

double Mult(double a, double b) {return a*b;}

double Div(double a, double b) {return a/b;}

double Calc(double a, double b, double (*pfn)(double,double)) {
	return pfn(a,b);
}


int main()
{
	double a=1,b=1;
	int x;
	do {
		cout << "1. Enter a,b:\n";
		cout << "2. Addition\n";
		cout << "3. Subtraction\n";
		cout << "4. Multiplication\n";
		cout << "5. Division\n";
		cout << "6. Exit\n";
		cin >> x;
		switch(x) {
		case 1: cout << "a, b = "; cin >> a >> b; break;
		case 2: cout << "Result = " << Calc(a,b,Add) << endl;break;
		case 3: cout << "Result = " << Calc(a,b,Sub) << endl;break;
		case 4: cout << "Result = " << Calc(a,b,Mult) << endl;break;
		case 5: cout << "Result = " << Calc(a,b,Div) << endl;break;
		case 6: break;
		default: cout << "Incorrect choice!\n";
		}
	} while(x != 6);
			
	return 0;
}

