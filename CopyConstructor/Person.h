#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;
	int age;

public:
	Person() : name(""), age(0)
	{
		cout << "기본 생성자 호출" << endl;
	}
	Person(string name, int age) : name(name), age(age)
	{
		cout << "매개변수가 있는 생성자 호출" << endl;

	}
	//&를 안붙이면 무슨 일이 일어나나요?
	Person(const Person& other) : name(other.name), age(other.age)
	{
		cout << "복사 생성자 호출" << endl;

	}
	//무한루프를 돌게 되지요.
	~Person()
	{
		cout << this->name << "에서 소멸자 호출" << this->getName() << endl;

	}
	string getName()
	{
		return this->name;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void printName()
	{
		cout << "이름 : " << this->name << endl;
	}
	int getAge()
	{
		return this->age;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void printAge()
	{
		cout << "나이 : " << this->age << endl;
	}
};