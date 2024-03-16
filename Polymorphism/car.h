#pragma once

#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	string color;
	int door;

	Car(string color, int door) {
		this->color = color;
		this->door = door;
	}
	void drive() {
		cout << "drive, Brrrr~~" << endl;
	}
	virtual void stop() {
		cout << "Car stop" << endl;
	}
	void printCar() {
		cout << "색상 : " << this->color << ", 문 : " << this->door << endl;
	}
};