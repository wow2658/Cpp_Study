#if 0
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str = "";
	cout << "주민등록 번호 입력 : ";
	cin >> str;

	cout << "-가 제거된 주민등록 번호 : ";
	for (auto& c : str) // 범위기반 for문이 막상 돌아가기 시작하면 c와 비교하는것은 str[0]부터다. 이건 포인터나 주소가 아니라 값이니까 레퍼런스 c와 맞붙는것이 이해된다. 이 부분이 헷갈렸었다.
	{
		if ('-' == c) continue;
		cout << c;
	}
	cout << endl;

	return 0;
}


#else
//string 배열
//string 기본형 타입처럼 얼마든 배열을 만들수 있다.
//string 배열은 2차원 배열과 원리가 똑같다.
//그렇다고 이중포인터랑 똑같이 봐버리면 안된다.

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string list[]{ "철수","영희","길동" };
	cout << list << endl; // 주소가 나온다.

	cout << list[0] << " " << &list[0] << endl;
	cout << list[1] << " " << &list[1] << endl;
	cout << list[2] << " " << &list[2] << endl;

	for (auto& s : list)
	{
		cout << (s + " 출석! \n");
	}
	return 0;
}

/*
07_에서
for (auto& c : str)에서 str은 std::string 객체이므로,
c는 char&, 즉 문자의 참조로 추론된다.

08_에서
for (auto& s : list)에서 list는 std::string 객체의 배열이므로,
s는 std::string&, 즉 문자열 객체의 참조로 추론된다.
*/
#endif