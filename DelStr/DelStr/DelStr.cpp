// DelStr.cpp : Defines the entry point for the console application.
//Да се дефинира функция, която изтрива всяко срещане на определен низ в друг даден низ.

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

char* DelStr(char* str1, char* str2)
{
	char* newstr = strstr(str1,str2);
	int size = strlen(str2);
	while(newstr != NULL) {
		int n = strlen(newstr);
		int m = strlen(str1);
		for (int i=m-n;i<m-size;i++)
		{
			str1[i]=str1[i+size];
		}
		str1[m-size]='\0';
		newstr = strstr(str1,str2);
	}
	return str1;
}

int main()
{
	char str1[100];
	cin>>str1;
	char str2[10];
	cin>>str2;
	char* n = DelStr(str1,str2);
	cout<<n<< endl;
	return 0;
}

