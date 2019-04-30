// 2D_dynamically_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned int N;
	cout<<"N=";
	cin>>N;

	int** ary = new int*[N];
	for(int i = 0; i < N; ++i)
		ary[i] = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		for(int j =0; j<N; j++)
		{
			cout<< "Enter arr["<<i<<"]["<<j<<"]=";
			cin>>ary[i][j];
		}
		
	}
	

	cout<<endl;
	for (int i = 0; i < N; i++)
	{
		for(int j =0; j<N; j++)
		{
			//cout<< "arr["<<i<<"]["<<j<<"]="<<ary[i][j]<<endl;
			cout<<ary[i][j]<<" ";
		}
		cout<<endl;
	}


	cout<<endl;
	int br=0;
	for (int i = 0; i < N; i++)
	{
		br = 0;
		for(int j =0; j<N; j++)
		{
			
			if(ary[i][j]==ary[j][i])
			{
				br++;
				
			}
		}
		if( br == N)
		{
			cout<<"index:"<<i<<endl;
		}
	}
	
	for(int i = 0; i < N; ++i) {
		delete [] ary[i];//delete corresponding array of every pointer ary[i]
	}
	delete [] ary;//delete the array of pointers
		
	return 0;
}

