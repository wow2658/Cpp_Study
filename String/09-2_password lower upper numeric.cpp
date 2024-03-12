// 사용자의 암호가 안전한지 검사하는 프로그램
// 대문자, 소문자, 숫자 모두 들어있어야 안전으로 간주

// 전에 풀었던 ascii counter를 범위로 나눠서 for문 돌고
// counter[str[i]]이 0인게 하나라도 걸리면 안전하지 않다라고 해보자

#include <iostream>
#include <string>
using namespace std;

#if 0 
int main(void)
{
	//cout << (int)'0'<<endl; //48
	//cout << (int)'9'<<endl; //57
	//cout << (int)'A'<<endl; //65
	//cout << (int)'Z'<<endl; //90
	//cout << (int)'a'<<endl; //97
	//cout << (int)'z'<<endl; //122

	int counter[256]{ 0 };
	string str{ "" };
	cout << "암호를 입력하세요 : ";
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		++counter[str[i]];
	}

	bool isincludeNum{ false };
	bool isincludeBIG{ false };
	bool isincludesmall{ false };


	for (int i = 48; i <= 57; i++)
	{
		if (counter[i] > 0)
		{
			isincludeNum = true;
			break;
		}
	}

	for (int i = 65; i <= 90; i++)
	{
		if (counter[i] > 0)
		{
			isincludeBIG = true;
			break;
		}
	}

	for (int i = 97; i <= 122; i++)
	{
		if (counter[i] > 0)
		{
			isincludesmall = true;
			break;
		}
	}

	if (0 == isincludeNum || 0 == isincludeBIG || 0 == isincludesmall)
	{
		cout << "안전하지 않습니다." << endl;
		return -1;
	}

	cout << "안전합니다." << endl;
	return 0;
}
#else
int main(void)
{
	string str{ "" };
	cout << "암호를 입력하세요 : ";
	getline(cin, str);

	bool is_lower{ false };
	bool is_upper{ false };
	bool is_numeric{ false };

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			is_lower = true;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			is_upper = true;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			is_numeric = true;
		}
	}

	if (!is_lower || !is_upper || !is_numeric)
	{
		cout << "안전하지 않습니다." << endl;
		return -1;
	}
	cout << "안전합니다." << endl;
	return 0;

	//if (is_lower && is_upper && is_numeric)
	//{
	//	cout << "안전합니다." << endl;
	//	return 0;
	//}
	//else cout << "안전하지 않습니다." << endl;
	//return -1;
}
#endif

