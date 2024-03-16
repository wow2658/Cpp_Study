#pragma once

#include "car.h"

class Fire_Car : public Car 
{
public:
	bool fire;

	Fire_Car(string color, int door, bool fire) : Car(color, door)
	{
		this->fire = fire;
	}

	void water()
	{
		cout << "water!!!!" << endl;
	}
	virtual void stop() override
	{
		cout << "Fire_Car stop" << endl;
	}
	void printFire_Car()
	{
		cout << "색상 : " << this->color << ", 문 : " << this->door << ", water : "
			<< this->fire << endl;
	}




};