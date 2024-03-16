#pragma once
#include "Tv.h"

//�ڽ� Ŭ���� WideTv ����
class WideTv : public Tv 
{	//9��
private:
	int inch;
public:
	WideTv() 
	{
		this->inch = 0;
		cout << "WideTv 기본 생성자 호출" << endl;
	}
	WideTv(int channel, int inch) : Tv(10) 
	{
		this->inch = inch;
		cout << "WideTv 매개변수 생성자 호출" << endl;
	}
	~WideTv() 
	{
		cout << "WideTv 소멸자 호출" << endl;
	}
	int getInch() 
	{
		return this->inch;
	}
	void setInch(int inch)
	{
		this->inch = inch;
	}
	void printWidtTv() 
	{
		cout << "WideTv의 채널 : " << this->getChannel() << endl;
		cout << "WideTv의 인치 : " << this->getInch() << endl;
	}
};
