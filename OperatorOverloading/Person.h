#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person 
{
private:
	int age;
	string name;
public:
	Person(int age, string name) 
	{
		this->age = age;
		this->name = name;
		cout << "Person생성자호출" << endl;
	}
	~Person() 
	{
		cout << "Person소멸자호출" << endl;
	}
	//friend함수 선언 (멤버 함수가 아니다) 
	friend void printPerson(Person person);
	//여기 바로 아래 내부에서 구현하는것이 막혀있지는 않지만, 외부에서 구현하는 것을 권장!
};

//! 위에서 friend함수 선언할 때 멤버함수가 아니라고 했다.
//! 때문에 범위연산자 :: 을 붙여버리면 Person한테는 그런 멤버 함수가 없는데? 하고
//! 오류를 내버린다.
//void Person::printPerson(Person person)
void printPerson(Person person) 
{
	cout << "Person( " << person.age << ", " << person.name << " )" << endl;
}