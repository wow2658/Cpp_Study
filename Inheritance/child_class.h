#pragma once

#include "parent_class.h"

class Child_Class : Parent_Class 
{
private:
	int data;
public:
	Child_Class(int data)
	{		
		this->data = data;
		cout << "Child_Class 매개변수 생성자 호출" << endl;
	}
	~Child_Class() 
	{
		cout << "Child_Class 소멸자 호출" << endl;
	}
	void c_print() 
	{
		
		Parent_Class::print(); //부모 클래스의 멤버 함수 호출하는 코드. 변수도 마찬가지다.
		cout << "부모 클래스의 멤버변수 age 출력 : " << Parent_Class::age << endl;
		cout << endl << endl;
		cout << "자식 클래스의 멤버변수 age 주소값 : " << &this->age << endl<<endl;
		cout << "자식 클래스의 멤버변수 age 출력 : " << this->age << endl;
		cout << "자식 클래스의 멤버변수 data 출력 : " << this->data << endl;
		cout << "자식 클래스의 멤버함수 c_print() 호출" << endl;
	}
};
