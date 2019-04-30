// errorsInTask.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
class A
{ public:
    A(int, int = 1);
    void A1()                  //не трябва да има същото име като класа
    { x = 0; y = x+1;
      cout << x << " " << y << endl;
    }
    int f1(); //const;
    int f2()  const;
	void print() const ;
  private:
    int x, y;
 };

A::A(int a = 0, int b)
 { x = a;
   y = b;
  // return x+y;    //konstr. ne wryshta nishto
 }
 void A::print() const   //v klasa nqma metod print
 { cout << x << " " << y << endl;
 }
 int A::f1() //const ne trqbva da e const
 { x++;
   return x;
 }
 int A::f2() const    // v klasa e definiran kato konstanten metod
 { return y;
 }

int main()
{
	A n;
	n.f1();
	n.f2();
	n.print();
	return 0;
}

