#pragma once

#include "animal.h"

class Dog : public Animal 
{

public:
	Dog() 
	{
		cout << "Dog 기본 생성자 호출" << endl;
	}
	~Dog() 
	{
		cout << endl;
		cout << "Dog 매개변수 생성자 호출" << endl;
	}
	void speak() 
	{
		cout << "강아지 멍멍" << endl;
	}
};