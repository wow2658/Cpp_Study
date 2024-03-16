#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student
{
	//friend 없으면 ostream 접근을 할 수 없다.
	friend ostream& operator<<(ostream& os, const Student& student);

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
};


//입출력 연산자는 반환형이 반드시 참조형이어야 한다. 결합법칙(연속콤보)에 의하여 실행되기 때문. 자주보며 어색함을 없애자.
ostream& operator<<(ostream& os, const Student& student) // os는 수정할거니까 const안줌. student는 속도를 조금 이득보고 싶어서 &써봄.
{
	os << "[나이 : " << student.age << ", 이름 : " << student.name << "]" << endl;
	return os;
}