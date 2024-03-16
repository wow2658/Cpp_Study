#pragma once

#include "shape.h"
using namespace std;

class Rectangle : public Shape 
{	
private:
	int width;
	int height;
public:
	Rectangle(int width = 0, int height = 0) 
	{
		this->width = width;
		this->height = height;
	}
	~Rectangle() 
	{
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
		return (this->width * this->height);
	}
	void printRectangle() 
	{
		cout << "width : " << this->getWidth() << ", height : " << this->getHeight() << endl;
	}
};
