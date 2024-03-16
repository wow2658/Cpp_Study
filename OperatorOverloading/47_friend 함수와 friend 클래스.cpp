//friend 함수 : 객체지향 언어의 중요한 원칙인 캡슐화, 은닉화를 무시하는 무법자. 그러니 웬만하면 사용을 자제하는것이 좋다.
//접근 지정자인 private public 등의 영향을 받지 않는다. -> 좀 특이한 녀석이니까 주의하라고 class {블럭}의 상위라인에 올려놔서 경각심을 주자.
//friend라고 허가를 내준 집주인의 멤버함수로 취급받지도 않는다. -> 헤더파일에서 외부구현하거나 사용처에서 호출시 범위 연산자 ::를 붙이지 않는다.
//ex) friend void func1() 같은 원형을 띈다.

#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

class A
{
	friend class B;

private:
	string secret;

public:
	A(string secret)
	{
		this->secret = secret;
		cout << "A 매개변수 생성자 호출" << endl;
	}
	~A()
	{
		cout << "A 소멸자 호출" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B 생성자 호출" << endl;
	}
	~B()
	{
		cout << "B 소멸자 호출" << endl;
	}
	void print(A a) //<- 복사생성자 2유형~~
	{
		cout << a.secret << endl; //crack! a의 secret은 private였다.
	}
};

int main(void)
{
	A a("하입보이");
	B b;
	b.print(a); // ~~2유형



	Person person(20, "김민지");
	printPerson(person); // 복사생성자 2유형~~
	//Person.h
	//***	void printPerson(Person person) <-- ~~2유형
	//***	{
	//***	cout << "Person( " << person.age << ", " << person.name << " )" << endl;
	//***	}

	return 0;
}