// char_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;


int main(int argc, _TCHAR* argv[])
{
	char name1[10] = "Peter";
	char name2[] = "Ivan";

	cout<<"name1="<<name1<<"  name2="<<name2<<endl<<endl;
	//================================================

	char name3[20];
	//name3 = "Hello"; // Error
	cout<<"Enter name:";
	cin>>name3;
	cout<<"\n You enter: "<< name3<<endl;
	//================================================

	cout<<"Enter again:";
	cin.ignore();//need for getline
	cin.getline(name3,10);
	cout<<"\n You enter: "<< name3<<endl<<endl;
	//================================================

	char *name4;
	int strsizen = 10;
	name4 = new char[strsizen];
	cout<<"Enter name4:";
	cin>>name4;// I version
		// II version
		//cin.ignore();
		//cin.getline(name4,10);
	strcpy(name3, "Hello, ");
	strcat(name3, name4);
	cout<<name3<<". Your name is with lenght="<<strlen(name4)<<endl<<endl;
	
	char *pn = name4;
	while(*pn)
	{
		cout<<*pn<<endl;
		pn++;
	}
	delete []name4;
	//================================================

	//cout<<"Hello"<<endl;
	return 0;
}

