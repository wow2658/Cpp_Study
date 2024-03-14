
#include "staticCircle.h"

int main(void) {

	cout << "정적 변수 count의 값(인스턴스 생성 이전) : " << Circle::count << endl;
	cout << "정적 변수 count의 주소값(인스턴스 생성 이전) : " << &Circle::count << endl;
	cout << endl;

	Circle* c1 = new Circle;
	cout << "정적 변수 count의 값 : " << Circle::count << endl;

	Circle* c2 = new Circle(100, 200, 30);
	cout << "정적 변수 count의 값 : " << Circle::count << endl;
	cout << endl << endl;


	cout << "정적 변수 count의 주소값(c1을 이용) : " << &c1->count << endl; //둘다 원래는
	cout << "정적 변수 count의 주소값(c2을 이용) : " << &c2->count << endl;	 //쓰면 안된다.
	cout << "정적 변수 count의 주소값(클래스명을 이용) : " << &Circle::count << endl;
	cout << endl << endl; //정적 변수는 클래스명::정적변수명으로 접근하는 것을 권장한다.

	delete c1;
	cout << "정적 변수 count의 값 : " << Circle::count << endl;
	delete c2;
	cout << "정적 변수 count의 값 : " << Circle::count << endl;

	return 0;
}