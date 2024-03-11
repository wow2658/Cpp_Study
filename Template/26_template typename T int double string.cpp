// 함수 템플릿과 클래스 템플릿, 템플릿 함수를 구별할 줄 알아야 한다.
#include <iostream>
#include <string>
using namespace std;

#if 0
// 일반적 프로그래밍(generic programming) : 함수 중복 정의의 단점은 코드가 길어지고 가독성이 떨어지는것.
// 이를 코드 재사용과 다양한 데이터 타입에 대하여 대응함으로써 극복.
template<typename T>
T get_max(T x, T y)
{
	if (x>y)
	{
		return x;
	}
	return y;
}

int main(void)
{
	int x = 10, y=20;
	int result = get_max(x,y);

	double d_x = 12.3, d_y=14.4;
	double d_result = get_max(d_x,d_y);

	cout<< "10과 20중에서 큰 값은 " << result <<"입니다.\n";
	cout<< "12.3과 14.4중에서 큰 값은 " << d_result <<"입니다.\n";

	return 0;
}
#endif

template <class T1, class T2>
void printAll(T1 a, T2 b)
{
	cout << "T1 = " << a <<endl;
	cout << "T2 = " << b <<endl;

}

int main(void)
{
	string s1 = "언리얼";
	string s2 = "화이팅";

	int num1 = 20;
	int num2 = 30;

	double d1 = 3.14;
	double d2 = 5.71;

	cout << "[string, string]\n";
	printAll(s1,s2);

	cout << "[string, int]\n";
	printAll(s1, num1);

	cout << "[double, int]\n";
	printAll(d1, num2);

	cout << "[double, string]\n";
	printAll(d2, s2);

	return 0;
}