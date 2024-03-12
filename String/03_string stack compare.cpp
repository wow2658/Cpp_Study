// string은 클래스다. 너무 자주써서 자료형으로 착각하는것은 아닌지? 조심하자
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	// 아래와 같이 선언을 하면 스택에 할당된것이다.
	string str1 = "언리얼"; // NULL로 초기화 하지 말것! char는 ' '로 초기화.
	string str2 = "뽀개자"; // NULL로 초기화 하지 말것! char는 ' '로 초기화.

	//문자열 결합
	string result = str1 + str2; // NULL로 초기화 하지 말것! char는 ' '로 초기화.

	cout << &str1 << endl;
	cout << &str2 << endl;
	cout << &result << endl;
	cout << result << endl;

	//문자열 비교
	if (str1 == str2) cout << "동일한 문자열입니다\n";
	else cout << "다른 문자열입니다\n";

	if (str1 < str2) cout << "str1이 사전순으로 앞에 있습니다.\n";
	else if (str1 > str2) cout << "str2이 사전순으로 앞에 있습니다.\n";
	else cout << "동일한 문자열입니다\n";


	return 0;
}
