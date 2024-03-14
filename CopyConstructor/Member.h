#pragma once
#include <iostream>
#include <string>
using namespace std;

class Member
{
private:
	string name;
	int age;
public:
	Member() : name(""), age(0) { cout << "기본 생성자 호출 " << endl; }
	Member(string name, int age) : name(name), age(age) { cout << this->name<<"의 매개변수 생성자 호출 " << endl; }
	Member(const Member& other) : name(other.name), age(other.age) { cout << this->name << "의 복사 생성자 호출 " << endl; }
	~Member() { cout << this->name << "의 소멸자 호출 " << endl; }
	string getName() { return this->name; }
	int getAge() { return this->age; }
	void printInfo() { cout << "이름 : " << this->name << ", 나이 : " << this->age<<endl; }
	void setName(string name) { this->name = name; }
};