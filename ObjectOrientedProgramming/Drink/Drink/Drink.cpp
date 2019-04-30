// Drink.cpp : Defines the entry point for the console application.
//

//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream> 
#include <string.h> 

using namespace std;

class Drink {
protected:
	char *name;
	double percent;
public:
	Drink() 
	{
		name = new char[1]; 
		strcpy(name, "");
		percent = 0.0;
	}
	~Drink() 
	{
		delete[] name;
	}
	Drink(const Drink &obj) 
	{
		int n = strlen(obj.name);
		name = new char[n+1];
		strcpy(name, obj.name);
		percent = obj.percent;
	}
	Drink(char *n, double p) {
		int size = strlen(n);
		name = new char[size+1];
		strcpy(name,n);
		percent = p;
	}
	void operator=(Drink obj) {
		int n = strlen(obj.name);
		delete[] name;
		name = new char[n+1];
		strcpy(name, obj.name);
		percent = obj.percent;
	}
	void SetName(char *n) {
		int size = strlen(n);
		name = new char[size+1];
		strcpy(name,n);
	}
	void SetPercent(double p) { percent = p;}
	double GetPercent() {return percent;}
	char* GetName() {return name;}
	void Print() {
		cout << "Drink: " << name << endl;
		cout << "Percent: " << percent << endl;
	}
	friend istream& operator>>(istream& in, Drink &d); 
	friend ostream& operator<<(ostream& out, Drink &d);
	bool operator>(Drink d) {
		if(strcmp(name,d.name) > 0) return true;
		else return false;
	}
	bool operator<(Drink d) {
		if(strcmp(name,d.name) < 0) return true;
		else return false;
	}
	bool operator==(Drink d) {
		if(strcmp(name,d.name) == 0) return true;
		else return false;
	}
};

class Bar {
protected:
	Drink *drinks; //ukazatel kam dinami4en masiv
	int size;
public:
	Bar() {drinks = NULL; size = 0;}
	Bar(Drink *dr, int n) {
		drinks = new Drink[n];
		for(int i = 0; i < n; i++)
			drinks[i] = dr[i]; //pred operator =
		size = n;
	}
	void AddDrink(Drink d) {
		size++;
		drinks[size] = d;//pred operator =
	}
	void RemoveDrink() {
		size--;
	}
	double Average() {
		double sum = 0;
		for(int i = 0; i < size; i++)
			sum += drinks[i].GetPercent();
		return sum/size;
	}
	Drink operator[](int i) {
		return drinks[i];
	}
	void SortByName() {
		Drink temp;
		for(int i = 0; i < size-1; i++)
			for(int j = size-1; j > i; j--)
				if(strcmp(drinks[j].GetName(),drinks[j-1].GetName()) < 0) {
					temp = drinks[j]; drinks[j] = drinks[j-1];
					drinks[j-1] = temp;
				}
	}
	

};

istream& operator>>(istream& in, Drink &d) {
	cout << "Enter name:";
	d.name = new char[100];
	in >> d.name;
	cout << "Enter percent:";
	in >> d.percent;
	return in;
}

ostream& operator<<(ostream& out, Drink &d) {
	out << "Name:" << d.name << endl;
	out << "Percent:" << d.percent << endl;
	return out;
}





int main()
{
	/*Drink d1;
	d1.Print();
	d1.SetName("Whisky");
	d1.SetPercent(40);
	d1.Print();
	Drink d2(d1);
	d2.Print();
	Drink d3;
	cin >> d3;
	cout << d3;
	d2.SetPercent(37);
	d3 = d2;
	d3.Print();*/
	Drink *array = new Drink[3];
	for(int i = 0; i < 3; i++)
		cin >> array[i]; //pred operator >>
	Bar b(array,3);
	b.SortByName();
	for(int i = 0; i < 3; i++)
		cout << b[i] << endl;
	
	return 0;
}