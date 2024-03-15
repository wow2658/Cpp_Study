#pragma once

#include <iostream>
using namespace std;

class Complex 
{
private:
	double re;
	double im;
public:
	Complex(double r = 0.0, double i = 0.0) 
	{
		this->re = r;
		this->im = i;
		cout << "생성자 호출" << endl;
	}
	~Complex() 
	{
		cout << "소멸자 호출" << endl;
	}
	void printComplex() 
	{
		cout << this->re << " + " << this->im << "i" << endl;
	}
	friend Complex add(Complex c1, Complex c2);
};
Complex add(Complex c1, Complex c2) 
{
	return Complex(c1.re + c2.re, c1.im + c2.im);
}