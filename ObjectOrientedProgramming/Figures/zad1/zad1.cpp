// zad1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "triange.h"
#include "circle.h"
#include "Prism.h"
#include "Conus.h"

using namespace std;

int main()
{
	Prism p[5];
	Conus c[5];
	int i,Count=0; 
    double minS,minV;
	cout << __TIME__ << endl;
	cout << __DATE__ << endl;
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	for(i = 0 ; i < 5 ; i++) {
		cout << "\n--------------------\n";
		cin >> p[i];
	}

	cout << "\n minS = " ; cin >> minS;
	cout << "\n minV = " ; cin >> minV;


	for(i = 0 ; i < 5 ; i++) {
		if ( p[i].CalcV() > minV && p[i].Lice() < minS) {
			cout << "\n--------------------\n";
		    cout << p[i];
			Count++;
		}
	}
	
	cout << "\n Count = " << Count << endl;
	system ("pause");
	return 0;
}

