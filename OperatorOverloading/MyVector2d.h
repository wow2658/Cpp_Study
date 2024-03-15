#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyVector
{
private:
	double x; 
	double y;
public:

	MyVector() : x(0.0), y(0.0)
	{
		cout << "기본 생성자 호출" << endl;
	}
	MyVector(double x, double y) : x(x), y(y)
	{

		cout << "매개변수 생성자 호출" << endl;
	}
	MyVector(const MyVector& other) : x(other.x), y(other.y)
	{
		cout << "복사 생성자 호출" << endl;
	}
	~MyVector()
	{

		cout << "소멸자 호출" << endl;
	}

	string toString()
	{
		return "(" + to_string(this->x) + ", " + to_string(this->y) + ")\n";
	}

	MyVector operator+(const MyVector& other)
	{
		MyVector v;
		v.x = this->x + other.x;
		v.y = this->y + other.y;

		return v;
	}


	MyVector operator-(const MyVector& other)
	{
		MyVector v;
		v.x = this->x - other.x;
		v.y = this->y - other.y;

		return v;
	}
};