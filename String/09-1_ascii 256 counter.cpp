// 영어 소문자만 다루는 버전
#if 0
//문자열을 입력받는다.
//한바퀴 돌면서 내가 준비해놓은 a[26]을 1씩 올린다
//a[0]은 a를 뜻한다. a[25]는 z를 뜻한다.
//a[i] 가 0이면 continue
//근데 배열에다가 하려니 ((a))의도 : a[i]이게 어렵다.
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str = "";
	cout << "문자열을 입력하시오 : ";
	cin >> str;
	int alpha[26] = { 0 };
	for (const auto s : str)
	{
		++alpha[s - 97];
	}

	for (int i = 0; i < 26; ++i)
	{
		if (0 == alpha[i]) continue;
		cout << (char)(i + 97) << " : " << alpha[i] << endl;
	}


	return 0;
} 

#else
//공백 특수문자 포함 모든 아스키코드 문자열를 커버하는 버전으로 만들어라.
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int counter[256]{ 0 };
	string str = "";
	getline(cin, str);

	for (int i = 0; i < str.size(); ++i)
	{
		++counter[str[i]];
	}

#if 1 // -> 중복안되게 개선할 것
	/*for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " : " << counter[str[i]] << endl;
	}
	return 0;*/

	bool isprint[256] = {false}; // 개선 성공!
	for (int i = 0; i < str.size(); ++i)
	{
		if(isprint[str[i]]) continue;
		cout << str[i] << " : " << counter[str[i]] << endl;
		isprint[str[i]] = true;
	}
	return 0;

#else // 내 방식으로 아스키코드 순으로 정렬 및 중복 없앰
	for (int i = 0; i < 256; ++i)
	{
		if (0 == counter[i]) continue;
		cout << (char)i << " : " << counter[i] << endl;
	}
#endif //
	return 0;
}

#endif
