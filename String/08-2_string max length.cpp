#include <iostream>
#include <string>
#define LEN 3
using namespace std;

int main(void)
{
	string str[LEN]{ "" };

	for (int i = 0; i < LEN; i++)
	{
		cout << "문자열을 입력하시오 : ";
		cin >> str[i];
	}

	string max = str[0];
	for (int i = 1; i < LEN; i++)
	{
		if (max.size() < str[i].size()) max = str[i];
	}
	cout << "제일 긴 문자열 : " << max << endl;

	return 0;
}