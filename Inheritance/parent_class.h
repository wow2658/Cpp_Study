#pragma once

#include <iostream>
using namespace std; //웬만하면 자식클래스에서 쓰자고 했지만 여기에서도 필요하기 때문에 사용

class Parent_Class 
{
private :

protected:
	int age;
public :
	Parent_Class()
	{
		this->age = 25;
		cout << "Parent_Class 기본 생성자 호출" << endl;
	}
	Parent_Class(int age) 
	{
		this->age = age;
		cout << "Parent_Class 매개변수 생성자 호출" << endl;
	}
	~Parent_Class()
	{
		cout << "Parent_Class 소멸자 호출" << endl;
	}
	void print()
	{
		cout << "부모 클래스의 age 주소값 : " << &this->age << endl;
		cout << "부모 클래스의 age 값 : " << this->age << endl;
		cout << "Parent_Class�� print() 호출" << endl;
	}
};
