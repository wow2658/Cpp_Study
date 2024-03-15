#pragma once
#include <iostream>
#include <string>
using namespace std;

class Box
{
private:
	string name;
	double length;
	double width;
	double height;
public:
	Box()
	{
		this->name = "";
		this->length = 0.0;
		this->width = 0.0;
		this->height = 0.0;
		cout << this->name << "의 기본 생성자" << endl;
	}
	Box(string name, double length, double width, double height)
	{
		this->name = name;
		this->length = length;
		this->width = width;
		this->height = height;
		cout << this->name << "의 매개변수 생성자" << endl;
	}
	~Box()
	{

		cout << this->name << "의 소멸자" << endl;
	}
	void display()
	{
		cout << this->name << " = (" << this->length << ", " << this->width << ", " << this->height << ")" << endl;
	}

	//대입연산자는 여기 클래스내부에서 구현까지 끝마쳐야한다. 밖에서 구현할 수 없다. 
	Box& operator=(const Box& box2)
	{
		//this->name = box2.name;
		this->length = box2.length;
		this->width = box2.width;
		this->height = box2.height;
		cout << this->name << "의 대입연산자" << endl;
		return *this;
	}

	Box(const Box& box2)
	{
		//this->name = box2.name;
		this->length = box2.length;
		this->width = box2.width;
		this->height = box2.height;
		cout << this->name << "의 복사생성자" << endl;
	}
	void setName(string name)
	{
		this->name = name;
	}
};

//밖에서 구현하면 오류나는것 확인
//Box::Box& operator=(const Box& box2)
//{
//	this->length = box2.length;
//	this->width = box2.width;
//	this->length = box2.height;
//	cout << this->name << "의 대입연산자" << endl;
//	return *this;
//}