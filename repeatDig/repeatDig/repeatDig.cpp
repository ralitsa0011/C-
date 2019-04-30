// repeatDig.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;



int main()
{
	int N;
	cin>>N;
	char str[100];
	_itoa_s(N,str,10);
	int flag = 0;
	for(int i = 0; i<strlen(str)-1;){
		for(int j = i+1; j<strlen(str);j++)
		{
			if(str[i]==str[j])
			{
				flag = 1;
				break;
				
			
			}
			
		}
		i++;
	}
	if(flag == 1) 
		cout<<"yes"<<endl;
	else cout<<"no"<<endl;
		return 0;
}

