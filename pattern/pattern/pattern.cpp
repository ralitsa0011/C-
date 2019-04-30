// pattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a=3,b=5;
	Swap(a,b);
	cout << a << " " << b << endl;
	double q = 0.5, r = -3.14;
	Swap(q,r);
	cout << q << " " << r << endl;
	char c1='a',c2='b';
	Swap(c1,c2);
	cout << c1 << " " << c2 << endl;
	
	
	return 0;
}

