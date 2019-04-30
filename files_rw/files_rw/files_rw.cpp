// files_rw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>  //FILE
#include <fstream> //
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	cout<<"Hello"<<endl;
	
	//========= C version =========================
	FILE *fp;
	char filename[30];
	strcpy(filename, "out.txt");
	fp= fopen(filename,"w");
	if (fp == NULL) 
	{
		printf("\t   ERROR: FILE NOT FOUND\n\n");						
	}
	else
	{
		int a=5;
		fprintf(fp,"Hello,\n my var a =%d\n\n", a);
	}
	fclose(fp);
	//==============================================
	
	strcpy(filename, "in.txt");
	fp= fopen(filename,"r");
	if (fp == NULL) 
	{
		printf("\t   ERROR: FILE NOT FOUND\n\n");						
	}
	else
	{
		char c;
		int a;
		char buf[20];
		while (!(feof(fp))) 
		{	
			
			if (fscanf(fp, "%d", &a) == 1) 
			{	
				printf("\t  I read int value=%d\n\n",a);
			}
			if (fscanf(fp, "%s", buf) == 1)
			{
				printf("\t  I read string value=%s\n\n",buf);
			}		
		}
	}
	fclose(fp);

	//=========================================================

	// ================ C++ version ===========================

	char buffer[256];
	
	//ofstream myoutfile("test.txt");
	ofstream myoutfile("test.txt", ios::out | ios::app); //append to previous file

	if (myoutfile.is_open())
	{
		int a = 55;
		myoutfile << "Text written in this file.";
		myoutfile << "\n";
		myoutfile << "Other line with text.\n";
		myoutfile << "My num is="<<a<<"\n";
		myoutfile.close();
	}
	else cout << "Unable to open file";

	
	
	ifstream myinfile("test.txt");
	
	int br=0;
	char ch;

	if (myinfile.is_open())
	{
		while (! myinfile.eof() )
		{
			myinfile.getline(buffer,100);
			cout << buffer << endl;

			/*
			//myinfile>>buffer;
			//cout << buffer << endl;
			*/


			/*
		    //count symbols in text

			myinfile.get(ch);
			if (ch!='\n')
				br++;
			*/
			
		}
    myinfile.close();
	}
	
	else cout << "Unable to open file"; 
	
	//cout<<endl<<"Number of symbols:"<<br<<endl;


	return 0;
}

