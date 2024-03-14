#pragma once
#include <iostream>
using namespace std;

class Circle 
{
private:
	int x;
	int y;
	int radius;

public:
	static int count; ////////////////////////////////////
	Circle() 
	{
		//this->count = 0;
		this->x = 0;
		this->y = 0;
		this->radius = 0;
		cout << "기본생성자 호출" << endl;
		count++;
	}
	//Circle(int x, int y, int radius, int count)
	Circle(int x, int y, int radius) 
	{
		this->x = x;
		this->y = y;
		this->radius = radius;
		//this->count = count;
		cout << "매개변수 생성자 호출" << endl;
		count++;
	}
	~Circle() 
	{
		cout << "소멸자 호출" << endl;
		count--;
	}
};

int Circle::count = 0; //////////////////////////////////////

