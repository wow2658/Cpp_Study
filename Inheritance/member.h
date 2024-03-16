#pragma once

#include <iostream>
#include <string>
using namespace std;

class Member 
{
private:

protected:
	int member_id;
	string name;
	string address;
public:
	Member()
	{
		this->member_id = 0;
		this->name = "";
		this->address = "";
		cout << "Member 기본 생성자 호출" << endl;
	}
	Member(int member_id, string name, string address) 
	{
		this->member_id = member_id;
		this->name = name;
		this->address = address;
		cout << "Member 매개변수 생성자 호출" << endl;
	}
	~Member() 
	{
		cout << "Member 소멸자 호출" << endl;
	}
	int getMember_Id() 
	{
		return this->member_id;
	}
	int num; //상속 접근지정자 디폴트값 확인용도
};
