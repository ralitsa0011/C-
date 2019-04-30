// Reverse Polish.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int size = 1024;
template <typename TT>
struct Stack {
	TT data[size];
	int top;
};

template <typename T>
void Init(T *s) {
	s->top = 0;
}

template <typename T>
bool IsEmpty(const T *s) {
	return (s->top == 0);
}

template <typename T, typename TT>
void Push(T *s, TT x) {
	s->data[s->top] = x;
	s->top++;
}

template <typename T, typename TT>
TT Pop(T *s) {
	if(IsEmpty(s))
		throw "Stack is empty";
	s->top--;
	return s->data[s->top];
}

template <typename T, typename TT>
int main()
{
	Stack<int> s;
	char str[20];
	cout << "Enter an expression in RPR:";
	cin >> str;
	int n = strlen(str);
	for(int i = 0; i < n; i++) {
		if(str[i] >= '0' && str[i] <= '9') 
			Push(&s, str[i]-'0');
		else {
			if(str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
				cout << "Incorrect input!\n";
				return 1;
			}
			int op1,op2,res;
			if(!IsEmpty(&s))
				op2 = Pop(&s); 
			else {
				cout << "Incorrect input!\n";
				return 1;
			}
			if(!IsEmpty(&s))
				op1 = Pop(&s); 
			else {
				cout << "Incorrect input!\n";
				return 1;
			}
			switch(str[i]) {
				case '+': res = op1+op2; break;
				case '-': res = op1-op2; break;
				case '*': res = op1*op2; break;
				case '/': res = op1/op2; 
			}
			Push(&s,res);
		}
	}

	cout << "The result of calculation is " << Pop(&s) << endl;

	return 0;
}

