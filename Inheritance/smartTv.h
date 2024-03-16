#pragma once
#include "Tv.h"

class SmartTv : public Tv 
{		
private:
	bool smart;
public:
	SmartTv() 
	{
		this->smart = false;
		cout << "SmartTv 기본 생성자 호출" << endl;
	}
	SmartTv(int channel, bool smart) : Tv(10)
	{
		this->smart = smart;
		cout << "SmartTv 매개변수 생성자 호출" << endl;
	}
	~SmartTv() 
	{
		cout << "SmartTv 소멸자 호출" << endl;
	}
	bool getSmart()
	{
		return this->smart;
	}
	void setSmart(bool smart)
	{
		this->smart = smart;
	}
	void smartOn(bool smart)
	{
		this->smart = true;
		cout << "on" << endl;
	}
	void smartOff(bool smart)
	{
		this->smart = false;
		cout << "off" << endl;
	}
	void printSmartTv() 
	{
		cout << "SmartTv의 채널 : " << this->getChannel() << endl;
		cout << "Smart 기능 상태 : " << boolalpha << this->getSmart() << endl;
	}
};
