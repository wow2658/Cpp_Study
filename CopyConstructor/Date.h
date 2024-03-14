#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date() : year(0), month(0), day(0) 
	{
		cout << "Date클래스 기본 생성자 호출됨" << endl;
	}
	Date(const Date& other) : year(other.year), month(other.month), day(other.day)
	{
		cout << "Date클래스 복사 생성자 호출됨" << endl;
	}
	Date(int year, int month, int day) : year(year), month(month), day(day) 
	{
		cout << "Date클래스 매개변수 생성자 호출됨" << endl;
	}
	~Date() {
		cout << "Date클래스 소멸자 호출됨" << endl;
	}
	void printDate() 
	{
		cout << this->year << "년 " << this->month << "월 " << this->day << "일" << endl;
	}
};
