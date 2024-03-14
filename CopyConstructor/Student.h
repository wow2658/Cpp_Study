#pragma once
#include "date.h"

class Student 
{
private:
	string name;
	Date birth;
public:
	Student(const Student& other) : name(other.name), birth(other.birth)
	{
		cout << "Student 클래스 복사 생성자 호출됨" << endl;
	}
	Student(string name, Date date) : name(name), birth(date)
	{
		cout << "Student 클래스 매개변수 생성자 호출됨" << endl;
	}
	~Student() 
	{
		cout << "Student 클래스 소멸자 호출됨" << endl;
	}
	void printStudent() 
	{
		cout << this->name << " : ";
		this->birth.printDate();
		cout << endl;
	}
};