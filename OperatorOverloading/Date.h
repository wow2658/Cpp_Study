#pragma once

#include <iostream>
using namespace std;

class Date 
{
private:
	int year;
	int month;
	int day;

public:
	Date(int year, int month, int day) 
	{
		this->year = year;
		this->month = month;
		this->day = day;
		cout << "Date 매개변수 생성자 호출" << endl;
	}
	~Date() 
	{
		cout << "Date 소멸자 호출" << endl;
	}
	friend bool equals(Date d1, Date d2);

	bool equals(Date d2) //이것을 friend로 변경해보자.
	{
		return this->year == d2.year && this->month == d2.month && this->day == d2.day;
	} 
};

bool equals(Date d1, Date d2) //this->가 아니라 d1. 을 이용하니까 중립적으로 보인다.
{
	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}