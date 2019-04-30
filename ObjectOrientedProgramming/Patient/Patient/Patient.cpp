// Patient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <string.h> 

using namespace std;

class Patient
{
protected:
	char* name;
	char* adress;
	char* ID;
public:
	Patient()
	{
		name = new char[1];
		strcpy(name,"");
		adress = new char[1];
		strcpy(adress,"");
		ID = new char [11];
		strcpy(ID,"");
	}
	Patient(const Patient &obj)
	{
		int l1=strlen(obj.name);
		name =  new char [l1+1];
		strcpy(name, obj.name);
		int l2= strlen(obj.adress);
		adress= new char [l2+1];
		strcpy(adress,obj.adress);
		int l3=strlen(obj.ID);
		ID=new char[l3+1];
		strcpy(ID, obj.ID);
	}
	Patient(char* n, char* a, char* i)
	{
		int l1=strlen(n);
		name =  new char [l1+1];
		strcpy(name, n);
		int l2= strlen(a);
		adress= new char [l2+1];
		strcpy(adress,a);
		int l3=strlen(i);
		ID=new char[l3+1];
		strcpy(ID, i);
	}
	~Patient()
	{
		delete []name;
		delete []adress;
		delete []ID;
	}
	void operator=(Patient &obj)
	{
		int l1=strlen(obj.name);
		delete []name;
		name =  new char [l1+1];
		strcpy(name, obj.name);
		int l2= strlen(obj.adress);
		delete []adress;
		adress= new char [l2+1];
		strcpy(adress,obj.adress);
		int l3=strlen(obj.ID);
		delete []ID;
		ID=new char[l3+1];
		strcpy(ID, obj.ID);
	}
	void SetName(char *n) 
	{
		int size = strlen(n);
		name = new char[size+1];
		strcpy(name,n);
	}
	void SetAdress(char *a) {
		int size = strlen(a);
		adress = new char[size+1];
		strcpy(adress,a);
	}
	void SetID(char *i) {
		int size = strlen(i);
		ID = new char[size+1];
		strcpy(ID,i);
	}
	void Print()
	{
		cout<<name<<endl;
		cout<<adress<<endl;
		cout<<ID<<endl;
	}
	char* GetName() {
		return name;
	}
	char* GetAddress() {
		return adress;
	}
	char* GetID() {
		return ID;
	}

	friend istream& operator>>(istream &in,Patient d);
	friend ostream& operator<<(ostream &out,Patient d);

	int GetAge() {
		int year = 10*(ID[0] - '0') + (ID[1] - '0');
		int age = 114 - year;
		return age;

	}

};

istream& operator>>(istream &in,Patient d)
{
	d.name = new char [100];
	in>>d.name;
	d.adress = new char [100];
	in>>d.adress;
	return in;
}
ostream& operator<<(ostream &out,Patient d)
{
	out<<d.name<<endl;
	out<<d.adress<<endl;
	return out;

}
class SickPatient : public Patient
{
	int day;
	char* diagnosis;
public:
	SickPatient() : Patient() //обръщение към конструктора на базовия клас да инициализира наследените полета
	{
		diagnosis = new char[1];
		strcpy(diagnosis,"");
		day=0;
	}
	SickPatient(const SickPatient &obj) ///////////////////////////: Patient(obj)
	{
		int n=strlen(obj.diagnosis);
		diagnosis=new char [n+1];
		strcpy(diagnosis, obj.diagnosis);
		day=obj.day;
	}
	~SickPatient()
	{
		delete []diagnosis;
	}
	void SetDiag(char *d) {
		int size = strlen(d);
		diagnosis = new char[size+1];
		strcpy(diagnosis,d);
	}
	void SetDay(int d) {day=d;}
	char* GetDiag() {return diagnosis;}
	int GetDay() {return day;}
	void Print()
	{
		cout<<diagnosis<<endl;
		cout<<day<<endl;
	}
	friend istream& operator>>(istream &in,SickPatient p);
	friend ostream& operator<<(ostream &out,SickPatient p);
	

};
istream& operator>>(istream &in,SickPatient p)
{
	cout << "Enter name: "; 
	in >> p.name;
	return in;
	
}
ostream& operator<<(ostream &out,SickPatient p)
{
	out<<p.name<<endl;
	out<<p.adress<<endl;
	out<<p.ID<<endl;
	out<<p.day<<endl;
	out<<p.diagnosis<<endl;
	return out;
}

class GP {
private:
	Patient lp[100];
	SickPatient lsp[100];
	int size_lp, size_lsp;
public:
	GP() {size_lp = size_lsp = 0;}
	GP(GP& list) {
		for(int i = 0; i < list.size_lp; i++)
			lp[i] = list.lp[i];
		size_lp = list.size_lp;
		for(int i = 0; i < list.size_lsp; i++)
			lsp[i] = list.lsp[i];
		size_lsp = list.size_lsp;
	}
	void operator=(GP list) {
		for(int i = 0; i < list.size_lp; i++)
			lp[i] = list.lp[i];
		size_lp = list.size_lp;
		for(int i = 0; i < list.size_lsp; i++)
			lsp[i] = list.lsp[i];
		size_lsp = list.size_lsp;
	}
	~GP() {}
	void AddPatient(Patient p) {
		size_lp++;
		lp[size_lp] = p;
	}
	void MovePatient(char *EGN) {
		int i = 0;
		while(strcmp(lp[i].GetID(), EGN) != 0)
			i++;
		Patient temp = lp[i];
		for(int j = i; j < size_lp-1; j++)
			lp[j] = lp[j+1];
		size_lp--;
		SickPatient sp;
		sp.SetName(temp.GetName());
		sp.SetID(temp.GetID());
		sp.SetAdress(temp.GetAddress());
		char str[100];
		cout << "Enter a diagnosis:"; cin >> str;
		int d;
		cout << "Enter a day:"; cin >> d;
		sp.SetDiag(str);
		sp.SetDay(d);
		size_lsp++;
		lsp[size_lsp] = sp;
	}
	void MoveSickPatient(char *EGN) {
		int i = 0;
		while(strcmp(lsp[i].GetID(), EGN) != 0)
			i++;
		SickPatient temp = lsp[i];
		for(int j = i; j < size_lp-1; j++)
			lsp[j] = lsp[j+1];
		size_lsp--;
		Patient p;
		p.SetName(temp.GetName());
		p.SetID(temp.GetID());
		p.SetAdress(temp.GetAddress());
		size_lp++;
		lp[size_lp] = p;
	}
	void Print(char* d)
	{
	int i = 0;
	while(i < size_lsp) {
		if(strcmp(lsp[i].GetDiag(), d) == 0)
			cout<<lsp[i];
		i++;
	}
	}
	void SortByAge() {
		for(int i = 0; i < size_lp-1; i++)
			for(int j = size_lp-1; j > i; j--) {
				int age1 = lp[j-1].GetAge();
				int age2 = lp[j].GetAge();
				if(age2 < age1) {
					Patient temp = lp[j];
					lp[j] = lp[j-1];
					lp[j-1] = temp;
				}
			}
	}
	int SickDays(int d) {
		int i = 0, sum = 0;
		while(i < size_lsp) {
			sum += (d - lsp[i].GetDay());
			i++;
		}
		return sum;
	}
};



int main()
{
	return 0;
}

