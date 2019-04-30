// word_reading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;


void Trim(char *str,int b,int e) {
	int n=(e+b)/2;
	for(int i = b;i<=n;i++)
		swap(str[i],str[e+b-i]);

	
}

int main()
{
	char str[100];
	cin.getline(str,100);
	int i = 0,b=0,e=0;
	while(str[i]!=' '&&str[i]!='\0')
	{
		i=b;


	str=Trim(str);
	cout<<str;
	
	return 0;
}



