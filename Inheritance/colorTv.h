#pragma once
#include "Tv.h"

class ColorTv : public Tv 
{		
private:
	string color;
public:
	ColorTv(int channel, string color) : Tv(channel) 
	{
		this->color = color;
		cout << "ColorTv 매개변수 생성자 호출" << endl;
	}
	~ColorTv() 
	{
		cout << "ColorTv 소멸자 호출" << endl;
	}
	string getColor() 
	{
		return this->color;
	}
	void setColor(string color) 
	{
		this->color = color;
	}
	void printColorTv() 
	{
		cout << "ColorTv의 채널 : " << this->getChannel() << endl;
		cout << "ColorTv의 색상 : " << this->getColor() << endl;
	}
};