#pragma once

#include "car.h"

class Ambulance : public Car 
{
public:
	bool siren;

	Ambulance(string color, int door, bool siren) : Car(color, door)
	{
		this->color = color;
		this->door = door;
		this->siren = siren;
	}
	void siren_alarm()
	{
		cout << "사이렌!!!!" << endl;
	}
	void printAmbulance_Car()
	{
		cout << "색상 : " << this->color << ", 문 : " << this->door << ", siren : "
			<< this->siren << endl;
	}
};
