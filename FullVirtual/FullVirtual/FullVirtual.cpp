// FullVirtual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class MovableShape {
protected:
	int x,y;
public: 
	MovableShape() { x = y = 0;}
	MovableShape(int a, int b) {
		x = a; y = b;
	}
	void Move(int dx, int dy) {
		x += dx; y += dy;
	}
	virtual double Perimeter() = 0;
	virtual double Surface() = 0;
	virtual void Print() = 0;
};

class Circle : public MovableShape {
protected:
	double radius;
public:
	Circle() : MovableShape() { radius = 0;}
	Circle(int a, int b, int r) : MovableShape(a,b) {radius = r;}
	double Perimeter() { return	6.28*radius;}
	double Surface() { return 3.14*radius*radius;}
	void Print() {
		cout << "Corner: " << x << " " << y << endl;
		cout << "Radius: " << radius << endl;
	}
};

class Square : public MovableShape {
protected:
	double size;
public:
	Square() : MovableShape() { size = 0;}
	Square(int a, int b, double s) : MovableShape(a,b) {size = s;}
	double Perimeter() { return	4*size;}
	double Surface() { return size*size;}
	void Print() {
		cout << "Corner: " << x << " " << y << endl;
		cout << "Size: " << size << endl;
	}
};

class Rectangle : public Square {
protected:
	double width;
public:
	Rectangle() : Square() { width = 0;}
	Rectangle(int a, int b, double s, double w) : Square(a,b,s) { width = w;}
	double Perimeter() { return	2*(size+width);}
	double Surface() { return size*width;}
	void Print() {
		cout << "Corner: " << x << " " << y << endl;
		cout << "Size: " << size << endl;
		cout << "Width: " << width << endl;
	}
};

int main()
{
	MovableShape *ptr;
	Circle c(1,1,5);
	Square s(2,2,3);
	Rectangle r(3,3,4,6);
	ptr = &c;
	cout << "Circle:" << endl;
	cout << "Surface = " << ptr->Surface() << endl;
	cout << "Perimeter = " << ptr->Perimeter() << endl;
	ptr->Print();
	ptr = &s;
	cout << "Square:" << endl;
	cout << "Surface = " << ptr->Surface() << endl;
	cout << "Perimeter = " << ptr->Perimeter() << endl;
	ptr->Print();
	ptr = &r;
	cout << "Rectangle:" << endl;
	cout << "Surface = " << ptr->Surface() << endl;
	cout << "Perimeter = " << ptr->Perimeter() << endl;
	ptr->Print();


	return 0;
}

