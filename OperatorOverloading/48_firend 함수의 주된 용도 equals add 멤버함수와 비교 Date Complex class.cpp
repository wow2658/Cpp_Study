//되도록 자제해야 한다는 friend는 언제 많이 쓰일까?
//주로 이항 연산자로 두 개의 피연산자를 객체로 둘 때
//가독성을 높이는 용도로 많이 쓰인다.

//결국 멤버함수나 프렌드함수나 비슷한 역할을 한다.
//그러니 웬만하면 멤버함수를 지향하고 프렌드함수는 반드시 필요한 경우에만 선별적으로 사용해야 한다.

//어느 경우에 프렌드 함수를 정의게 나은가?
//두 개 이상의 객체에 관련이 된다면 프렌드 함수가 이점이 있고
//오직 하나의 객체에만 관련이 된다면 멤버 함수로 정의하는 것이 좋다.
#include "Date.h"
#include "Complex.h"

int main(void)
{
	Date d1(1996, 1, 23);
	Date d2(1999, 4, 27);


	if (!d1.equals(d2))		{ cout << "다릅니다." << endl; }
	if (equals(d1, d2)) //마치 내장함수처럼 중립적이고 깔끔해졌다.
	{
		cout << "같습니다." << endl;
	}
	else
	{
		cout << "다릅니다." << endl;
	}

	cout << boolalpha << equals(d1, d2) << endl;

	cout << "==============================================================" << endl;
	
	Complex c1(1.0, 2.0), c2(3.0, 4.0);
	
	Complex c3 = c1.add(c2);
	Complex c4 = add(c1,c2); //friend

	c3.printComplex();
	c4.printComplex();


	return 0;
}
