#include <iostream>
#include <string>
using namespace std;

template <typename T>
void print_arr(T a[], int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		++cnt;
	}
	cout << "총 루핑수 : " << cnt << endl;
} // 문제점이 무엇인가?? char일때도 루핑을 100번 다 돌아버린다.
  // \0 을 인식해서 멈출수 있는데 말이다.
  // 
  // 이때 템플릿 특수화를 이용하여 따로 처리를 해보자
template <>
void print_arr(char a[], int n)
{
	cout << a << endl;
}

int main(void)
{
	char c_arr[100] = "언리얼 화이팅!!";
	int i_arr[100] = { 1,2,3,4,5 };

	print_arr(c_arr, 100);
	print_arr(i_arr, 5);

	return 0;
}