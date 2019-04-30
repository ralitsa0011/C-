// dynamic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

class Str {
private:
	char *str;
public:
	
	static int num;
	Str() { str = new char[1]; strcpy(str,"");num++;}
	Str(char *s) {
		str = new char[strlen(s)+1];
		strcpy(str,s);
		num++;
	}
	Str(Str &obj) {
		str = new char[strlen(obj.str)+1];
		strcpy(str,obj.str);
		num++;
	}

	~Str() {
		delete[] str;
		num--;
	}
	void Print(char *msg) {
		cout << msg << (void *)str << "  ";
		cout << str << endl;
	}
	static int ReturnStat() {
		int x = num;
		return x;
	}
};

int Str::num = 0;

int main()
{
	Str s1("name");
	s1.Print("s1 = ");
	cout << s1.ReturnStat()<<endl;
	{Str s2 = s1;
	s2.Print("s2 = ");
	cout << Str::ReturnStat()<<endl;
	cout << s1.ReturnStat()<<endl;
	cout << s2.ReturnStat()<<endl;
	}
	s1.Print("s1 = ");
	cout << Str::ReturnStat()<<endl;
	return 0;
}

