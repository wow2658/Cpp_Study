#pragma once
#include <iostream>
#include <string>
using namespace std;

class Calculator 
{
private:
	int temp = 0;
public:
	Calculator()
	{
		cout << "기본 생성자 호출" << endl;
		++count;
	}

	static int count;

	long add(long x, long y)
	{
		//인스턴스 멤버 함수에서는 정적 멤버 함수를 사용하는데 문제가 없다.
		//호출하는 방법도 잘 익혀두자.
		this->temp = Calculator::multiply(2, 2);
		return x + y + this->temp;
	}
	long substract(long x, long y)
	{
		return x - y;
	}


	//정적 멤버 함수
	static long multiply(long x, long y)
	{
		//this->temp = 5; //error
		//	정적 멤버 함수에서는 this를 사용할 수가 없다.
		//	this': can only be referenced inside non-static member functions 
		//  non-static data member initializers
		int temp = 5;
		//  정적 멤버 함수에서는 인스턴스 멤버 함수or변수도 호출할 수가 없다. 
		//substract(10, 5);
		return x * y + temp;
	}
	static long divide(long x, long y)
	{
		//static은 static을 잘만 부른다. 동시점에서 둘은 메모리를 데이터 영역에서 할당받았기 때문이다.
		//return multiply(10, 10); //풀어도 오류 안나는 것 확인
		return x / y;
	}
	static int getCount() {
		return count;
	}
	~Calculator() {
		cout << "소멸자 호출" << endl;
		--count;
	}
};

int Calculator::count = 0;