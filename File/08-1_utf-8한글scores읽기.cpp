#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

int main(void)
{
	std::locale::global(std::locale("ko_KR.utf8"));
	ifstream is("scores.txt", ios::in); 

	if (!is)
	{
		cerr << "파일 열기 실패" << endl;
		exit(1);
	}

	string str = ""; // string 버전으로 해도 utf-8이면 한글깨진다
	while (!is.eof())
	{
		getline(is, str);
		cout << str << endl;
	}

	cout << endl;


	return 0;
}