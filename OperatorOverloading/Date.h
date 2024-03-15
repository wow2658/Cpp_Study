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
};

bool equals(Date d1, Date d2) 
{
	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}