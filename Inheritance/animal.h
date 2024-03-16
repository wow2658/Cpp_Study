#pragma once

#include <iostream>
#include <string>
using namespace std;

//�θ� Ŭ���� Animal�� ����
class Animal 
{

public:
	int age;

	Animal() 
	{
		this->age = 0;
		cout << "Animal 기본 생성자 호출" << endl;

	}
	Animal(int age) 
	{
		this->age = age;
		cout << "Animal 매개변수 생성자 호출" << endl;

	}
	~Animal() 
	{
		cout << "Animal 소멸자 호출" << endl;
	}
	void speak() 
	{
		cout << "동물이 말을하네" << endl;
	}
};