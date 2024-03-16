#pragma once

#include <iostream>
//using namespace std;	//부모 클래스가 있는 헤더파일에서는 using namespace를 생략 하는게 좋다.
//자식 클래스에서 중복으로 또 선언하면서 낭비를 하는 실수를 할 수 있기 때문이다.
class Shape 
{
private:
	int x;
	int y;
public:
	Shape(int x = 0, int y = 0) 
	{
		this->x = x;
		this->y = y;
	}
	~Shape() 
	{
	}
	int getX() 
	{
		return this->x;
	}
	int getY() 
	{
		return this->y;
	}
	void setX(int x) 
	{
		this->x = x;
	}
	void setY(int y) 
	{
		this->y = y;
	}
	void printPoint() 
	{
		std::cout << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;
	}
};
