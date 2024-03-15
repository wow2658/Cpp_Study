#pragma once
#include <iostream>
#include <string>
using namespace std;

class Member 
{
	//private :

public:
	int num;
	char* name;
	string name2;
	//나는 파라미터로 들어온 name을 변경하지 않을것이고 ROM에 영역에있는 ""의 주소값을 받아와 포인터변수 name에 저장할 것이며 그것을 char로 해석하겠다.
	Member(int num = 0, const char* name = "") 
	{
		this->num = num;
		//클래스에 char* 처럼 포인터변수 있으면 아래처럼 new로 동적 메모리 할당하는 콤보가 자주쓰인다. 이 과정에서 얕은복사의 약점이 드러나므로 긴장해야한다.
		//! strlen() : 문자열의 길이를 반환하는 함수. char는 \0 들어갈 공간을 수동으로 +1해서 만들어 놔줘야한다.
		this->name = new char[strlen(name) + 1];



		//strcpy_s() : 문자열을 복사하는 함수. 
		//! 여기에서도 size로 +1을 꼭해줘야 오류가 나지않는다.
		strcpy_s(this->name, strlen(name) + 1, name);



		cout << this->name<< "의 매개변수 생성자 호출" << endl;
	}
	~Member() 
	{
		//new char[]로 할당했으니 delete[]로 해제한다.
		string name2 = this->name;
		delete[] this->name;
		cout << name2 << "의 소멸자 호출" << endl;
	}
	void printMember() 
	{
		cout << "번호 : " << this->num << ", 이름 : " << this->name << endl;
	}
	
#if 1
	Member& operator=(const Member& member2) 
	{
		//1.원래 있던 동적 메모리를 소멸시킨다.
		delete[] this->name;
		this->num = member2.num;

		//2.새롭게 동적할당을 한다.
		this->name = new char[strlen(member2.name) + 1];

		//3.member2의 name값을 복사한다.
		strcpy_s(this->name, strlen(member2.name) + 1, member2.name);
		cout << this->name << "의 대입 연산자 호출" << endl;
		return *this;

		//? 왜 위와같이 귀찮게 새롭게 만들어서 대입하는걸까?
		//	-> name의 길이가 다르니까!
	}
#endif
};
