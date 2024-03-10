//예외 전달: 예외는 함수 범위를 넘어서 전달될 수도 있다. call하는 다른 함수에서 throw 해주는 경우를 실습해보자.

#include <iostream>
using namespace std;

int dividePizza(int, int persons);

int main(void)
{
	int pizza_slices = 0;
	int persons = 0;
	int slices_per_person = 0;

	try //catch가 반드시 짝으로 하나쯤은 있어야 컴파일에서 오류가 안난다.
	{
		cout << "피자 조각수를 입력 : ";	cin >> pizza_slices;
		cout << "사람수를 입력 : ";			cin >> persons;

		slices_per_person = dividePizza(pizza_slices, persons);
		cout << "한 사람당 피자 조각은 " << slices_per_person << "조각입니다.\n";
	}
	catch (int e) //throw를 잡는 catch가 없으면 abort()함수가 불러와져 오류를 일으키고 종료한다.
	{
		cout << "사람 수는 " << e << "명일 수 없습니다.\n";
	}
	return 0;
}

int dividePizza(int pizza_slices, int persons)
{
	if (0 == persons || 0 > persons)
	{
		throw persons; //예외를 전달하고 있다.
	}

	return pizza_slices / persons; //위에서 예외가 발생했으면 여기까지는 도달하지않고 throw에서 main으로 넘어가고 끝난다.
}