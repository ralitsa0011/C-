// MeetString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

char* MaxStr(char *strings[], int size) {
	int *meets = new int[size];
	for(int i = 0; i < size; i++)
		meets[i] = 0;
	for(int i = 0; i < size; i++) {
		char *st = strings[i];
		for(int j = 0; j < size; j++) {
			if(strcmp(st, strings[j]) == 0)
				meets[i]++;
		}
	}
	int max = meets[0], k = 0;
	for(int i = 1; i < size; i++)
		if(meets[i] > max) {
			max = meets[i]; k = i;
		}
	return strings[k];
}


int main()
{
	char *strings[] = {"abcf", "abcd", "abcd", "jkkk", "abcf", "jkkk", "jkkk"};
	cout << MaxStr(strings,7) << endl;
	return 0;
}

