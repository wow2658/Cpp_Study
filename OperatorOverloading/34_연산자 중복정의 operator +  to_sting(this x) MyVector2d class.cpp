#include "MyVector2d.h"

int main(void)
{
	MyVector v1(3.0, 4.0);
	MyVector v2{ 7.0, 6.0 };

				//v1.operator+(v2);
	MyVector v3 = v1 + v2;
	MyVector v4 = v1 - v2;
	cout<< v3.toString();
	cout<< v4.toString();

	return 0;
}