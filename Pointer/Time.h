#pragma once
#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time() : hour(0), minute(0), second(0)
	{

	}
	Time(int hour, int minute, int second) :
			 hour(hour), minute(minute), second(second)
	{

	}
	int getHour() const
	{
		return this->hour;
	}
	int getMinute() const
	{
		return this->minute;
	}
	int getSecond() const
	{
		return this->second;
	}
	void setHour(int hour)
	{
		this->hour = hour;
	}
	void setMinute(int minute)
	{
		this->minute = minute;
	}
	void setSecond(int second)
	{
		this->second = second;
	}
	void printTime()
	{
		cout << "Time = " << this->hour << ":" << this->minute
			<< ":" << this->second << endl;
	}
};
