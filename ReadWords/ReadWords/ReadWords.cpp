// ReadWords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

void NextWord(char *str, int &begin, int &end) {
	while(str[begin] == ' ') begin++;
	end = begin;
	while(str[end] != ' ' && str[end] != '\0') end++; //end spira v/u parvija interval
	end--; //end se vrashta v/u poslednija simvol ot dumata
}


int main()
{
	char str[1000];
	cin.getline(str,1000);
	int i = 0, b = 0, e = 0;
	int br = 0;
	while(str[i] != '\0') {
		NextWord(str,b,e);
		bool flag = true;
		if((e-b) < 3) flag = false;
		for(int j = b; j <= e; j++) {
			if((str[j] < 'A' || str[j] > 'Z') && (str[j] < 'a' || str[j] > 'z')) {
				flag = false; break;
			}
		}
		if(flag) 
			br++;
		e++;
		b = i = e;
	}
	cout << br << endl;
	return 0;
}

