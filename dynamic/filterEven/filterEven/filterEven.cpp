// filterEven.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>

using namespace std;

bool isEven(int a) { return a % 2 == 0; }
void filterArray(int arr[], int size,bool(*pfnPred)(int))
{
	int l = size;
	int i=0;
	while(i<l)
	{
		if(!pfnPred(arr[i])) {
			for(int j = i; j < l; j++)
				arr[j] = arr[j+1];
			l--;

		}
		else i++;
	}
	for(i=l;i<size;i++)
	{
		arr[i]='\0';
	}


}
int main()
{
	int arr[10] = {3,11,10,7,20,19,35,40,27,30};
	filterArray(arr,10,isEven);
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";


	return 0;
}

