#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
		cout << "Point 매개변수 생성자 호출" << endl;
	}
	~Point()
	{
		cout << "Point 소멸자 호출" << endl;
	}
	void printPoint()
	{
		cout << "(" << this->x << ", " << this->y << ")" << endl;
	}
};
