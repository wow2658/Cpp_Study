#include "Smartpoint.h"

int main(void) {

	cout << endl << "만들어본 스마트포인터" << endl;
	SmartPoint sp1 = new Point(10, 20); //point 만들때 한번, 그리고 주소를 반환
										//smartpoint는 주소를 매개변수로 받기로 되어있었으니 또 한번
	SmartPoint sp2 = new Point(30, 40); 

	(*sp2).printPoint(); //이거는 익숙한데
	sp1->printPoint();   //이거는 아직 낯설다. sp1::으로 생각하니 좀 편해졌는데 괜찮은 연상방법인지 알아봐야겠다.

	cout << endl << "기본제공 스마트포인터" << endl;


	unique_ptr<Point> ptr = make_unique<Point>(100, 200);
	ptr->printPoint();
	(*ptr).printPoint();
	cout << endl;
	return 0;
}