// DecToHex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int base = 16;


int main()
{
	int x,br=0;
	cin >> x;
	char str[20];
	while(x > 0) {
		int rem = x % base;
		if(rem > 9) 
			str[br] = 'A' + (rem-10);
		else
			str[br] = rem + '0';
		br++;
		x /= base;
	}
	str[br] = '\0';
	for(int i = br-1; i >= 0; i--)
		cout << str[i];
	cout << endl;
	return 0;
}

