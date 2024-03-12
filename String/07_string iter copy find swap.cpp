#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str = "unreal";

	//C style
	for (int i = 0; i < str.length(); ++i)
	{
		cout << str[i];
	}
	cout << endl;

	//iterator
	string::iterator iter = str.begin();
	for (iter; iter < str.end(); ++iter)
	{
		cout << *iter;
	}
	cout << endl;

	//copy, find, swap
	char arr[100]{ ' ' };
	int len{ 0 };
	string s1{ "unreal" };
	string s2{ "real" };

	len = s1.copy(arr, 3, 1); // index 1에서 3만큼 복사해와라, int 길이를 반환 해준다.
	arr[len] = '\0'; //브레이크 걸어주기. 문자배열이기 때문에 반드시 추가해줄것!
	cout << len << endl;
	cout << arr << endl;

	cout << s1.find(s2) << endl;
	cout << s1.find(s2,1) << endl; // index 1부터 찾아라. 부담줄여주기 but 지나쳤다면 쓰레기값 출력 오류(못찾았을때랑 같다)

	swap(s1,s2); //s1과 s2의 포인터를 교환, s1과 s2 자체를 포인터라고 하는것은 적절하지 않다. 객체이기 때문이다. 포인터는 그안에 멤버로서 추상화 개념으로 포함되어 있다. 그렇다고 직접 접근은 못한다.
	cout << s1<< endl;
	cout << s2<< endl;

	return 0;
}