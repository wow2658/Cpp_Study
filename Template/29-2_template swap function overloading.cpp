#include <iostream>
#include <string>
using namespace std;

template <typename T>
void swap_values(T& x, T& y)
{
	cout << "넘어온 값" << endl;
	cout << "x : " << x << ", y : " << y << endl;

	T temp = 0;
	temp = x;
	x = y;
	y = temp;

	cout << "값을 바꾼 후 함수내부" << endl;
	cout << "x : " << x << ", y : " << y << endl;


}

//함수 중복 정의

void swap_values(char* s1, char* s2)
{
	int len = 0;
	len = (strlen(s1) >= strlen(s2)) ? strlen(s1) : strlen(s2);
	char* tmp = new char[len + 1];
	cout << "넘어온 값" << endl;
	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;

	strcpy_s(tmp, len+1, s1); // len으로 적으면 오류나니깐 주의
	strcpy_s(s1, len+1, s2);  // 왜 오류가 나는지도 생각해보시오
	strcpy_s(s2, len+1, tmp);
	cout << "값을 바꾼 후 함수내부" << endl;
	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;


}

int main(void)
{
	int x = 10, y = 20;
	swap_values(x, y);
	cout << "main함수 내부" << endl;
	cout << "x : " << x << ", y : " << y << endl;

	char s1[10] = "UNREAL";
	char s2[10] = "WORLD";
	swap_values(s1,s2);
	cout << "main함수 내부" << endl;
	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;

	return 0;
}