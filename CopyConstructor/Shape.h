#pragma once
#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
	int x;
	int y;
public:
	Shape() {
		this->x = 0;
		this->y = 0;
		cout << "부모클래스 Shape의 기본 생성자 호출" << endl;
	}
	Shape(int x, int y) {
		this->x = x;
		this->y = y;
		cout << "부모클래스 Shape의 매개변수 생성자 호출" << endl;
	}

	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	~Shape() {
		cout << "부모클래스 Shape의 소멸자 호출" << endl;
	}
};