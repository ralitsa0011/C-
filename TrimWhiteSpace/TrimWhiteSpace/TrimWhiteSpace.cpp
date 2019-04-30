// TrimWhiteSpace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

char* TrimWhiteSpace(char *pInput) {
	int size = strlen(pInput);
	int i = 0;
	while(i < size) {
		if(pInput[i] == ' ' && pInput[i+1] == ' ') {
			int j = i;
			while(pInput[j] != '\0') {
				pInput[j] = pInput[j+1];
				j++;
			}
		}
		else
			i++;
	}
	return pInput;
}

int main()
{
	char *str = new char[20];
	cin.getline(str,20);
	str = TrimWhiteSpace(str);
	cout << str << endl;
	return 0;
}

