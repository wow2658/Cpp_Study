#include <iostream>
#include "Circle.h"
using namespace std;

int main(void) {
	//가볍게 const 관련 몸풀기
	int x = 100;
	int y = 500;

	const int* cl_ptr = &x;
	//*c_ptr = 1000;	
	cl_ptr = &y;

	int* const cr_ptr = &x;
	*cr_ptr = 500;
	//cr_ptr = &y;	

	const int* const clr_ptr = &x;
	//*clr_ptr = 500;	
	//clr_ptr = &y;

	//-------------------------------------------------------------//

	Circle* p = new Circle();
	const Circle* pConstObj = new Circle();
	Circle* const pConstPtr = new Circle(); //int* const에만 익숙해서 이거 보고 움찔하지말자

	cout << "pCircle->radius : " << p->getRadius() << endl;
	cout << "pConstObj->radius : " << pConstObj->getRadius() << endl;
	cout << "pConstPtr->radius : " << pConstPtr->getRadius() << endl;

	int temp = 0;
	cin >> temp;

	p->setRadius(30);
	p = pConstPtr;

	//pConstObj->setRadius(30);
	pConstObj = p;

	pConstPtr->setRadius(temp);
	//pConstPtr = p;

	cout << "p->radius은 pConstPtr랑 같아야됨 : " << p->getRadius() << endl;					//10으로 착각하지 말자
	cout << "pConstObj->radius은 p랑 같아야됨 : " << pConstObj->getRadius() << endl;			//10으로 착각하지 말자2
	cout << "pConstPtr->radius은 " << temp << "이어야됨 : " << pConstPtr->getRadius() << endl;
	//결국 셋이 같은 값
	return 0;
}