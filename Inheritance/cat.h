#pragma once

#include "animal.h"

class Cat : public Animal 
{

public:
	Cat() 
	{
		cout << "Cat 기본 생성자 호출" << endl;
	}
	~Cat()
	{
		cout << endl;
		cout << "Cat 매개변수 생성자 호출" << endl;
	}
	void speak() 
	{
		cout << "고양이 야옹" << endl;
	}

};