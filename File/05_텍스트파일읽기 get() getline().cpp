#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
	ifstream is("경로\\noRAII.txt", ios::in); //txt파일이 ANSI타입이 아니면 깨진다. utf-8과의 차이점 조사할 것.

	if (!is)
	{
		cerr << "파일 열기 실패" << endl;
		exit(1);
	}


	// 한글자씩 불러오는 버전
	//char ch = ' ';
	//int cnt = 0;
	//while (is) or while (!is.eof())
	//{
	//	is.get(ch);
	//	cout << ch;
	//	++cnt;
	//}

	// 한줄씩 불러오는 버전
	string str = "";
	int cnt = 0;
	while (is)
	{
		getline(is, str); //#include <string> 필요
		cout << str;
		++cnt;
	}


	cout << endl;

	cout << "총 루핑 수 : " << cnt << endl;
	cout << "파일 읽기 성공" << endl;


	return 0;
}