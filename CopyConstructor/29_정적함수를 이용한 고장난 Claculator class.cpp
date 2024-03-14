//정적 멤버 함수(메소드)
//데이터 메모리 영역에 프로그램 실행과 동시에 할당된다.
//인스턴스 생성없이도 클래스명::정적 멤버함수명() 으로 호출이 가능하다.
//static 멤버 함수의 {블럭} 안에는 static변수와 지역변수만 사용가능하다.
//static 기준에서는 인스턴스가 아직 만들어진게 아니라서
//this도 못쓰고 인스턴스의 멤버변수도 못쓰는 것이다.

#include "Calculator.h"

int main(void) {
	//인스턴스 멤버함수는 인스턴스를 생성하고 
	//참조변수명, 인스턴스 함수명을 통해서 호출할 수 있다.
	//Calculator::add(10, 5);
	//Calculator::substract(10, 5);

	//정적 멤버함수는 인스턴스 생성도 안했는데 접근이 가능하다.
	cout << "static long multiply(10, 5, temp) : " << Calculator::multiply(10, 5) << endl;
	cout << "static long divide(10, 5) : " << Calculator::divide(10, 5) << endl;
	//그냥 막 가져와서 쓰는게 참 신기하다.
	cout << "생성된 인스턴스 수 : " << Calculator::getCount() << endl; //0

	Calculator calc1;
	//1.인스턴스를 생성하고 2.호출을 인스턴스 통해서 하니까 컴파일 성공한다.
	cout << "인스턴스 멤버 함수 add(10, 5, temp) : " << calc1.add(10, 5) << endl;
	cout << "인스턴스 멤버 함수 substract(10, 5) : " << calc1.substract(10, 5) << endl;

	cout << "생성된 인스턴스 수 : " << Calculator::getCount() << endl; //1

	return 0;
}