#pragma once
#include <iostream>
#include <string>
using namespace std;



class Tv 
{ 
private:
	int channel;
public:
	Tv() 
	{
		this->channel = 1;
		cout << "부모 클래스 Tv 기본 생성자 호출" << endl;
	}
	Tv(int channel)
	{
		this->channel = channel;
		cout << "부모 클래스 Tv 매개변수 생성자 호출" << endl;
	}
	~Tv()
	{
		cout << "부모 클래스 Tv 소멸자 호출" << endl;
	}
	void channelUp()
	{
		this->channel++;
		cout << "현재 채널 : " << this->channel << endl;
	}
	void channelDown() 
	{
		this->channel--;
		cout << "현재 채널 : " << this->channel << endl;
	}
	int getChannel() 
	{
		return this->channel;
	}
	void setChannel(int channel) 
	{
		this->channel = channel;
	}
};
