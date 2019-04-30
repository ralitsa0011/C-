// StrToInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int ReadNumber(char *str, int &i) {
	int x = 0;
	while(str[i] >= '0' && str[i] <= '9') 
		x = 10*x + (str[i++]-'0');
	if((str[i] < '0' || str[i] > '9') && str[i] != '\0') return 0;
	else return x;
}
long strToInt(char* str)
{
	int x;
	for(int i = 0; str[i] != '\0'; ) {
		
		int sign = 1;
		if(str[i] == '-' || str[i] == '+') {
			if(str[i] == '-') sign = -1;
			i++;
			x = sign * ReadNumber(str,i);
			
		}
		else
			if(str[i] >= '0' && str[i] <= '9') {
				x = ReadNumber(str,i);
				
			}
			else
				i++;
	}
	return x;
	

}
int main()
{
	char str[100];
	cin>>str;
	if(strlen(str)>=10)
	{
	cout<<"Error";
	return 1;
	}
	int n = strToInt(str);
	cout<<n<<endl;

	return 0;
}

