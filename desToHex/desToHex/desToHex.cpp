// desToHex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{

	cout<<"Enter str="; 
	char st[9], str[100];// the last el. is for \0
	cin>>str;
	unsigned long n;
	if(strlen(str) >= 9) {
		cout << "Incorrect input!\n";
		return 1;
	}
	strcpy_s(st,str);
	if(n = strtoul(st,NULL, 16))
	{
		cout<<"num="<<n<<"\n";
	}
	else
	{
		cout<<"Error";
	}
	return 0;
}+

