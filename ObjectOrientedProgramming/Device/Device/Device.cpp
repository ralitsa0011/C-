// Device.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

class Device
{
protected:
	char* mark;
	char* model;
	double price;
public:
	Device()
	{
		mark =  new char[1];
		strcpy(mark,"");
		model = new char[1];
		strcpy(model,"");
		price  = 0;
	}
	Device(const Device &obj)
	{

		int l=strlen(obj.mark);
		mark  = new char [l+1];
		strcpy(mark, obj.mark);
		int n=strlen(obj.model);
		model  = new char [n+1];
		strcpy(model, obj.model);
		price=obj.price;
	}

	void operator=(Device &obj)
	{
		int l=strlen(obj.mark);
		delete [] mark;        //
		mark  = new char [l+1];
		strcpy(mark, obj.mark);
		int l1=strlen(obj.model);
		delete [] model;        //
		model  = new char [l1+1];
		strcpy(model, obj.model);
		price=obj.price;
	}
	Device(char* m,char* mk, double p)
	{
		int l=strlen(m);
		mark  = new char [l+1];
		strcpy(mark, m);
		int l1=strlen(mk);
		model  = new char [l1+1];
		strcpy(model, mk);
		price=p;
	}

	void setMark(char* m)
	{
		int l=strlen(m);
		mark  = new char [l+1];
		strcpy(mark, m);
	}
	void setModel(char* mk)
	{
		int l=strlen(mk);
		model  = new char [l+1];
		strcpy(model, mk);
	}
	void setPrice(double p)
	{
		price = p;
	}
	char* getMark()
	{
		return mark;
	}
	char* getModel()
	{
		return model;
	}
	double getPrice()
	{
		return price;
	}
	~Device()
	{
		delete []mark;
		delete []model;
	}
	friend istream& operator>>(istream &in,Device &p);
	friend ostream& operator<<(ostream &out,Device &p);


};
istream& operator>>(istream &in,Device &p)
{
	p.mark = new char[100];
	in>>p.mark;
	p.model = new char[100];
	in>>p.model;
	in>>p.price;
	return in;

}

ostream& operator<<(ostream &out,Device &p)
{
	out<<p.mark<<endl;
	out<<p.model<<endl;;
	out<<p.price<<endl;
	return out;
}

class BrokenDevice : public Device
{
protected:
	char* symptom;
	int day;
public:
	BrokenDevice() : Device() 
	{
		symptom = new char [1];
		strcpy(symptom,"");
		day = 0;
	}
	BrokenDevice(const BrokenDevice& obj)
	{
		int n = strlen (symptom);
		symptom = new char [n+1];
		strcpy(mark,obj.mark);
		int m =  strlen (model);
		model = new char [m+1];
		strcpy(model, obj.model);
		price = obj.price;
	}
	~BrokenDevice()
	{
		delete [] symptom;
	}


};  
class Serv 
{
	Device list1[100];
	BrokenDevice list2[100];
	int size1;
	int size2;
public:
	Serv()
	{
		size1=0;
		size2=0;
	}
	~Serv(){}


};
int main()
{
	Device a;
	a.setMark("reno");
	cout<<a;
	
}

