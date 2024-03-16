#include "rectangle.h"

int main(void) {

	Shape shape(10, 20);
	Rectangle rect(100, 200);

	//다형성
	//Shape* sh = new Rectangle(); //이건 잘 알겠는데
	//Shape sh = rect;			   //이건 좀 낯설다
	

	shape.printPoint();
	rect.printPoint();
	rect.setX(10);
	rect.setY(30);
	rect.printPoint();

	rect.printRectangle();

	cout << endl;

	//visual studio 2022 신기능인 Memory Layout을 보면 더 쉽게 이해할 수 있다.
	cout << "shape의 바이트 크기 : " << sizeof(shape) << endl;
	cout << "rect의 바이트 크기 : " << sizeof(rect) << endl;
	cout << endl << endl;
	cout << "사격형의 면적 : " << rect.getArea() << endl;
	return 0;
}