#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student 
{
private:
	int age;
	string name;
public:
	Student(int age = 0, string name = "") 
	{
		this->age = age;
		this->name = name;
		cout << "생성자 호출" << endl;
	}
	friend ostream& operator<<(ostream& os, const Student& student) 
	{
		return os;
	}
};
