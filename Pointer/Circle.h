#pragma once
#include <iostream>
using namespace std;

class Circle
{
private:
	int radius;
public:
	Circle() : radius(10) {}
	~Circle() {}
	int getRadius() const { return this->radius; }
	void setRadius(int _radius) { this->radius = _radius; }
};
