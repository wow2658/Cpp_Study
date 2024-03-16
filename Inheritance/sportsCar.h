#pragma once

#include "car.h"

class SportsCar : public Car 
{	
private:
	bool turbo;
public:
	SportsCar() : turbo(false) 
{
		cout << "자식 기본 생성자 호출" << endl;
	}
	SportsCar(bool turbo) 
{
		this->turbo = false;
		cout << "자식 매개변수 생성자 호출" << endl;
	}
	~SportsCar() 
	{
		cout << "자식 소멸자 호출" << endl;
	}
	bool getTurbo() 
	{
		return this->turbo;
	}
	void setTurbo(bool turbo) 
	{
		this->turbo = turbo;
	}
	void printTurbo()
	{
		cout << "현재 Turbo의 상태 : " << boolalpha << this->getTurbo() << endl;
	}

	void printSpeed() //부모에도 있는 함수를 오버라이딩 한것
	{
		cout << "현재 SpeedCar의 속도 : " << this->getSpeed() << endl;
		cout << "자식클래스의 speed 멤버변수의 주소값 : " << &this->speed << endl; //부모에서 speed를 private 영역에 놓으면 오류나는것 확인
	}
};
