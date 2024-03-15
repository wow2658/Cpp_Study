#pragma once

#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time(int hour = 0, int minute = 0, int second = 0) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
		cout << "생성자 호출" << endl;
	}
	~Time() {
		cout << "소멸자 호출" << endl;
	}

	bool operator==(const Time& time2) {
		return ((this->hour == time2.hour)
			&& (this->minute == time2.minute)
			&& (this->second == time2.second));
	}

	bool operator!=(const Time& time2) {
		return (!(this->hour == time2.hour)
			|| !(this->minute == time2.minute)
			|| !(this->second == time2.second));

		//return !(*this == time2);
	}
};
