#include "rectangle.h"

int main(void) {

	Rectangle rect;
	cout << "사각형의 면적" << rect.getArea() << endl;

	cout <<  endl;

	Rectangle rect_vari(10, 20);
	cout << "사각형의 면적" << rect_vari.getArea() << endl;
	cout << endl;
	return 0;
}