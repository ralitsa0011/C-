// onlyPosNum.cpp : Defines the entry point for the console applicati
//Да се напише програма, която въвежда число N 
//между 1 и 100 и след това въвежда N реални числа в някакъв масив. 
	//След това масивът трябва да се обработи и от него да се премахнат всички отрицателни числа. 
//	Да не се използва допълнителен масив. Резултатът да се изведе на екрана.

#include "stdafx.h"
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	int N;
	cin>>N;
	if(!cin)
	{
		cout<<"Error! Bad input!"<<endl;
		return 1;
	}
	if(N<1 || N>100)
	{
		cout<<"Incorrect input!"<<endl;
		return 1;
	}
	double arr[100];
	for (int i = 0; i< N;i++)
	{
		cin>>arr[i];	
	}
	for(int i=0; i<N; i++)
	{
			if(arr[i]<0)
			{
				N--;
				while(i < N)
				{
					arr[i] = arr[i+1];
					i++;
				}
			i=N-i-1;
		
			}
		

	}
	
	for (int i = 0; i< N;i++)
		cout<<arr[i]<<" ";
	return 0;
}

