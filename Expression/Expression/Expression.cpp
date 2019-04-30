// Expression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int N = 32;
const int size = 1024;

struct Operators {
	char letter;
	char sign;
	int priority;
	int assoc;
} op[N];

template <typename T>
struct Stack {
	T data[size];
	int top;
};

template <typename T>
void Init(Stack<T> *s) {
	s->top = 0;
}

template <typename T>
bool IsEmpty(const Stack<T> *s) {
	return (s->top == 0);
}

template <typename T>
void Push(Stack<T> *s, T x) {
	s->data[s->top] = x;
	s->top++;
}

template <typename T>
T Pop(Stack<T> *s) {
	if(IsEmpty(s))
		throw "Stack is empty";
	s->top--;
	return s->data[s->top];
}

int GetPriority(char ch) {
	int k = 0;
	while(op[k].letter != ch && k < N) 
		k++;
	if(k == N)
	{cout << "Incorrect input!"; exit(1);}
	return op[k].priority;
}

char GetSign(char ch) {
	int k = 0;
	while(op[k].letter != ch && k < N) 
		k++;
	if(k == N)
	{cout << "Incorrect input!"; exit(1);}
	return op[k].sign;
}

void ToRPR(char *str_init, char *str) {
	Stack<char> expr;
	Init(&expr);
	int n = strlen(str_init);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		char ch;
		if(str_init[i] == ' ') {
			if(str_init[i-1] >= '0' && str_init[i-1] <= '9')
				str[cnt++] = ' ';
			continue;
		}
		if(str_init[i] >= '0' && str_init[i] <= '9') 
		{str[cnt++] = str_init[i];continue;}
		if(str_init[i] == '-') 
		{str[cnt++] = 'm'; continue;}
		if(str_init[i] == '(')
		{Push(&expr,str_init[i]); continue;}
		if(str_init[i] == ')') {
			while((ch = Pop(&expr)) != '(')
				str[cnt++] = GetSign(ch);
			continue;
		}
		ch = str_init[i];
		if(IsEmpty(&expr)) {
			Push(&expr,ch);
			continue;
		}
		int pr = GetPriority(ch);
		do {
			if(IsEmpty(&expr))
				break;
			char symbol = Pop(&expr);
			if(symbol == '(') {
				Push(&expr,symbol);
				break;
			}
			int prSymb = GetPriority(symbol);
			if(pr <= prSymb) {
				char sgn = GetSign(symbol);
				str[cnt++] = sgn;
			}
			else {
				Push(&expr,symbol);
				break;
			}
		} while(true);
		Push(&expr,ch);
	}
	while(!IsEmpty(&expr))
		str[cnt++] = GetSign(Pop(&expr));
}

int GetNumber(char *str, int &i) {
	int num = 0;
	while(str[i] >= '0' && str[i] <= '9') {
		num = num*10 + (str[i]-'0');
		i++;
	}
	return num;
}


int CalcRPR(char *str) {
	int cnt = strlen(str);
	Stack<int> s;
	Init(&s);
	int i = 0;
	while(i < cnt) {
		if(str[i] == ' ')
		{i++; continue;}
		if(str[i] == 'm') {
			i++;
			Push(&s, -GetNumber(str,i));
			continue;
		}
		if(str[i] >= '0' && str[i] <= '9') 
			Push(&s, GetNumber(str,i));
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
			i++;
		}
	}
	return Pop(&s);
}

int main()
{
	fstream f1;
	f1.open("operators.txt", ios::in);
	int cnt = 0;
	while(!f1.eof()) {
		f1 >> op[cnt].letter;
		f1 >> op[cnt].sign;
		f1 >> op[cnt].priority;
		f1 >> op[cnt].assoc;
		cnt++;
	}
	char str_init[50],str[50]="";
	cout << "Enter an expression:";
	cin.getline(str_init,50);
	ToRPR(str_init,str);
	cout << str << endl;
	cout << "The result of calculation is " << CalcRPR(str) << endl;
	return 0;
}



