#pragma once
#include <iostream>
using namespace std;

class Number
{

#if 1
private:
	int* num;
public:
	Number(int* num)
	{
		this->num = num;
		cout << "매개변수 생성자" << endl;
	}
	~Number()
	{
		delete num; //메모리 누수를 여기에서 방지. smartpointer 처럼
		cout << "소멸자 호출" << endl;
	}
	//* 연산자 중복 정의
	//주소가 아닌 객체를 넘겨줘야한다. 그러므로 반환형에 Ref를 넘긴다. 거기에 맞게 return으로는 *num을 넘긴다. 
	// 
	//Number& operator*()		//class 전신 본인이 직접 나설 때
	//{
	//	return *this;
	//}
	int& operator*() const		//num이라는 포인터 변수를 이용할 때 
	{
		return *num;
	}

	//-> 연산자 중복 정의
	//객체가 아니라 주소를 넘겨줘야한다. 그러므로 반환형에 ptr을 넘긴다. 거기에 맞게 return으로는 num을 넘긴다.
	// 
	//Number* operator->()
	//{
	//	return this;
	//}
	int* operator->() const
	{
		return num;
	}
	void printNumber()
	{
		cout << "num의 값 : " << *this->num << endl;
	}

#else
private:
	int num;
public:
	Number(int num)
	{
		this->num = num;
		cout << "매개변수 생성자" << endl;
	}
	~Number()
	{
		cout << "소멸자 호출" << endl;
	}
	//* 연산자 중복 정의
	//주소가 아닌 객체를 넘겨줘야한다. 그러므로 반환형에 Ref를 넘긴다. 거기에 맞게 return으로는 *num을 넘긴다. 
	// 
	Number& operator*()		//class 전신 본인이 직접 나설 때
	{
		return *this;
	}
	//int& operator*() const		//num이라는 포인터 변수를 이용할 때 
	//{
	//	return *num;
	//}

	//-> 연산자 중복 정의
	//객체가 아니라 주소를 넘겨줘야한다. 그러므로 반환형에 ptr을 넘긴다. 거기에 맞게 return으로는 num을 넘긴다.
	// 
	Number* operator->()
	{
		return this;
	}
	/*int* operator->() const
	{
		return num;
	}*/

	void printNumber()
	{
		cout << "num의 값 : " << this->num << endl;
	}

#endif



};