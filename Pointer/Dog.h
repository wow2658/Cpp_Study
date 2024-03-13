#pragma once
#include <iostream>
#include <string>
using namespace std;

class Dog
{
private:
	string name;
	int age;
public:
	Dog() : name("페퍼"), age(1) //역시 여기서 초기화 하는게 제일 빠르다
	{
		cout << "생성자 호출" << endl;
		this->name = "브랜디";
		this->age = 2;
		cout << this->name << this->age << endl; //브랜디2
		cout << "this는 주소를 지닌 포인터인가? 생성자에서 : " << this << endl;
	}
	~Dog()
	{
		cout << "소멸자 호출" << endl;
		cout << "this는 주소를 지닌 포인터인가? 소멸자에서 : " << this << endl;

	}
public:
	string getName()
	{
		return this->name;
	}
	int getAge()
	{
		return this->age;
	}
};