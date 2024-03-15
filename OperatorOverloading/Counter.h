#pragma once
#include <iostream>
using namespace std;

class Counter {
private:
	int value;
public:
	Counter() : value(0)
	{
		cout << "기본 생성자" << endl;
	}
	~Counter() 
	{
		cout << "소멸자" << endl;
	}
	int getValue() 
	{
		return this->value;
	}
	Counter& operator++() //본체에 영향을 미쳐야하니까. 복사하면 안되니까. 연속콤보 가능해야 하니까.
	{
		++(this->value);
		return *this;
	}
	Counter operator++(int) //이건 그냥 구별용도라고 한다.
	{
		Counter temp = *this;
		++(this->value);
		return temp; //복사생성자 호출유형 3번을 기억하라
	}				 //전위 연산자가 후위 연산자보다 이득인 부분
};
