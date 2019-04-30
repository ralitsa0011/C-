// pfnCompare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool before(double a, double b) { return a < b;}

void sort(double arr[], int size, bool (*pfnCompare)(double,double))
{
	int i,j,index;
	double min;
	for(i=0;i<size-1;i++){
		min = arr[i]; index = i;
		for(j=i+1;j<size;j++){
			if(pfnCompare(arr[j],min))
			{
				min = arr[j]; index = j;
			}
		}
		if(index != i) swap(arr[index], arr[i]);
	}
}
int main()
{
	double arr[10] = {3,11,10,7,20,19,35,40,27,30};
	sort(arr,10,before);
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	return 0;
}

