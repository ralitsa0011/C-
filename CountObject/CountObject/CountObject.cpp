// CountObject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Counter
{
	private:
      static int count;//deprecate to init
	public:
    Counter()
    {
       count++;
    }  
	~Counter()
	{
		count--;
	}
      
       
    static int GetCount() {

         return count;
    }
};

int Counter::count = 0;//!!!

/*
    �� �� �������� �������, ����� ������ ������ �� ����� ���,
    �� �������� ������� ������� � ���������� �������.
*/
char* substr(const char* source, char* result, unsigned start, unsigned length)
{
    char* resultStart = result;
    // ������������� �� � start
    while(*source && start > 0)
    {
        ++source;
        --start;
    }

    // ��������� �� �������� � result, ������
    // �������� length ������ ������� ���, ������
    // �� �������� ����
    while(*source && length > 0)
    {
        *result = *source;
        // ����������� ��� �������� �������
        ++result;
        ++source;

        --length;
    }

    // ��������� ������������� ����
    *result = '\0';

    return resultStart;
}

const unsigned STRING_MAXLENGTH = 20;
void testSubStr()
{
    char source[STRING_MAXLENGTH];
    // ��������� �������� �� ������������
    // ��� ���������� >> � ���� ���� �� ��� ���������...
	cout<<"enter string:";
    cin >> source;

    char result[STRING_MAXLENGTH];

    unsigned startPosition, length;

    cout << "Start position of the substring: "; cin >> startPosition;
    cout << "Length of the substring: "; cin >> length;

    substr(source, result, startPosition, length);
    cout << "The substring is: " << result << endl;
}


int main()
{
	Counter a;
	Counter b;
	Counter c;

	cout<<"There are:"<<Counter::GetCount()<<" objects"<<endl<<endl;

	//testSubStr();
	char ch[]="15";
	int num;
		num = atoi(ch);
	cout<<"num="<<num;

	return 0;
}

