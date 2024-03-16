#pragma once

#include <iostream>
using namespace std;

class Car
{
private:


protected:
	int speed;
public:
	Car() : speed(0)
	{
		cout << "부모 기본 생성자 호출" << endl;
	}
	Car(int speed)
	{
		cout << "부모 매개변수 생성자 호출" << endl;
		this->speed = speed;
	}
	~Car()
	{
		cout << "부모 소멸자 호출" << endl;
	}
	int getSpeed()
	{
		return this->speed;
	}
	void setSpeed(int speed)
	{
		this->speed = speed;
	}
	void printSpeed()
	{
		cout << "현재 speed : " << this->getSpeed() << endl;
		cout << "부모 클래스 speed 멤버변수의 주소값 : " << &this->speed << endl;
	}
};
