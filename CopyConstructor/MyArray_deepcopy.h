#pragma once
#include <iostream>
#include <string>
using namespace std;
class MyArray
{
private:
	int size;
	int* data;
public:
	string name;
	MyArray(int size, string name) : size(size), data(new int[size]), name(name)
	{
		cout << "매개변수 생성자 호출" << endl;
		for (size_t i = 0; i < this->size; i++)
		{
			this->data[i] = 0;
		}
	}
	MyArray(const MyArray& other) : size(other.size), data(new int[other.size]),name(other.name) //this->data = other.data가 아니라 아예 새로 만들어서 새주소 전달
	{
		cout << "복사 생성자 호출" << endl;
		for (size_t i = 0; i < size; i++)
		{
			this->data[i] = other.data[i];
		}

	}
	int getSize()
	{
		return this->size;
	}
	int* getData()
	{
		return this->data;
	}
	~MyArray()
	{
		if (nullptr != data)
		{
			delete[] this->data;
			//cout << "소멸자 if문 내부 호출" << endl;
		}
		cout << this->name << "의 소멸자 호출" << endl;
	}
};