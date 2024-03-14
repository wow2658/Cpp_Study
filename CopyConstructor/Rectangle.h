#pragma once
#include "shape.h"

class Rectangle : public Shape 
{	
private:
	int width;
	int height;
public:
	Rectangle() 
	{
		this->width = 0;
		this->height = 0;
		cout << "자식 Rectangle 기본 생성자 호출" << endl;
	}
	Rectangle(int width, int height) 
	{
		this->width = width;
		this->height = height;
		cout << "자식 Rectangle 매개변수 생성자 호출" << endl;
	}
	int getWidth() 
	{
		return this->width;
	}
	int getHeight() 
	{
		return this->height;
	}
	void setWidth(int width) 
	{
		this->width = width;
	}
	void setHeight(int height) 
	{
		this->height = height;
	}
	int getArea() 
	{
		int area = 0;
		area = this->width * this->height;
		return area;
		//return this->width * this->height;
	}
	~Rectangle()
	{
		cout << "자식클래스 Rectangle 소멸자 호출" << endl;
	}
};