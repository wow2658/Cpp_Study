#include "sportsCar.h"

int main(void)
{
	//! 부생 자생 자소 부소의 진실
	//호출과 실행을 구별해서 생각해보았는가?
	//부모 생성자가 먼저 찍혔다고 그게 먼저 호출됐다는 것을 말하는 것일까??
	//호출 자체는 자식 생성자가 먼저 호출된거다.
	//부모 생성자는 호출은 늦었으나 실행을 먼저 한 것이다. 이 차이를 알아두자.
	//소멸자의 경우에는 호출된 녀석이 바로바로 실행된 것이고,
	//생성자는 일단 다 호출해놓고 부모부터 실행해서 쭈르륵 내려와서 부생 자생 자소 부소의 순서가 된 것이다.

	SportsCar sc;
	cout << endl << endl;

	Car car; //부모클래스의 생성자만 나오는 것이 당연. 

	//부모클래스는 자식클래스의 멤버를 사용할 수 없다.
	//car.setTurbo(true);

	//그러나 자식클래스는 부모클래스의 멤버를 사용할 수 있다.
	sc.setSpeed(500);
	sc.printSpeed();
	cout << endl << endl;

	//본인이 본인의 고유 멤버 사용하는 것은 아무 문제가 없다.
	car.setSpeed(300); //부모가 부모꺼
	car.printSpeed();
	sc.setTurbo(true); //자식이 자식꺼
	sc.printTurbo();
	sc.printSpeed();

	//sc::Car.printSpeed(); super같은게 따로 없다고 한다.
	cout << endl << endl;




	return 0;
}