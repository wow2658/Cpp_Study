#pragma once
#include "Point.h"

class SmartPoint {
private:
	Point* ptr;
public:
	SmartPoint(Point* ptr) //생성자 매개변수 안에 포인터가 들어간게 중요하다.
	{
		this->ptr = ptr;
		cout << "SmartPoint 매개변수 생성자 호출" << endl;
	}

	Point& operator*() const //저번의 int* num처럼 class 전신이 나서는게 아니라 멤버 포인터 변수를 이용하는 방법
	{
		return *ptr;
	}

	Point* operator->() const
	{
		return ptr;
	}

	~SmartPoint()
	{
		cout << "SmartPoint 소멸자 호출" << endl;
		delete ptr;
	}
};
