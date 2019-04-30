// Words.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

bool Word(char *str, int &begin, int &end) {
	int i = begin;
	while(str[i] != ' ') i++;
	begin = i+1;
	end = begin;
	while(str[end] >= 'a' && str[end] <= 'z') end++;
	if(str[end] == ' ')
		return true;
	else 
		return false;
}

int main()
{
	char *str = new char[20];
	cin.getline(str,20);
	int a=0,b=0;
	bool flag = Word(str,a,b);
	cout << a << " " << b << endl;

	return 0;
}

