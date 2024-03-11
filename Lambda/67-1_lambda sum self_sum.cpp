// 람다식이란?
// 나중에 실행될 목적으로 다른 곳으로 전달될 수 있는 함수 객체

// 사용하는 이유는?
// 코드가 간결함과 편리함 때문이다.

// 언제쓰면 좋은가?
// 함수의 로직이 짧고 1회성일때 좋다.

// 함수형 프로그래밍에서 많이 쓰이는 개념이다.
// C++에서는 함수가 1급 객체가 아니다.

// 1급객체가 무엇인가?
// 변수나 데이터 구조 안에 담을 수 있고, 인자값으로 전달 가능하며, 반환 값으로도 사용이 되는 것

#include <iostream>
#include <typeinfo>
using namespace std;

int main(void)
{
	// 람다식(이름이 없는 익명함수)을 sum이라는 auto 변수에 대입한 것 
	auto sum = [](int x, int y) {return x + y; };
	auto self_sum = [](int x, int y) 
	{
		x+=1;
		y+=1;
		return x + y; 
	}	(10,30);

	cout << "sum 타입 : " << typeid(sum).name() << ", 바이트 크기 : " << sizeof(sum) << endl;

	// sum 타입 : class `int __cdecl main(void)'::`2'::<lambda_1>, 바이트 크기 : 1

	cout << sum(1,8) << endl;
	cout << sum(10,80) << endl;
	cout << self_sum << endl;


	return 0;
}