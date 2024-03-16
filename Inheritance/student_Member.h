#pragma once

#include "member.h"

class Student_Member : Member //이렇게 접근지정자를 안써놓으면 default값으로 private로 처리된다.
							  //상속 접근지정자의 기본값은 한글로는 검색해도 잘 안나오는 부분이었다.
							  //영어로 검색해야 stackoverflow에서 좀 볼 수 있고
							  //직접 검증을 통해 확신할 수 있었다.
							  //만약 자식 쪽이 class가 아니라 struct였으면 public으로 간주된다.  
{	
private:
	string school_name;
public:
	Student_Member(int member_id, string name, string address, string school_name) 
		: Member(member_id, name, address) //! 가장 중요한 부분!!! 이렇게 하면 부모의 매개변수 생성자를 부를수 있다.
	{
		this->school_name = school_name;
		cout << "Student_Member 매개변수 생성자 호출" << endl;
	}
	~Student_Member() 
	{
		cout << "Student_Member 소멸자 호출" << endl;
	}


	void setName(string name) 
	{
		this->name = name;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	void setMember_Id(int member_id) 
	{
		this->member_id = member_id;
	}
	void setSchoolName(int school_name) 
	{
		this->school_name = school_name;
	}
	string getName()
	{
		return this->name;
	}
	string getAddress() 
	{
		return this->address;
	}
	string getSchoolName()
	{
		return this->school_name;
	}
	int getMember_Id() 
	{
		return this->member_id;
	}
};