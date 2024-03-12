#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str = "";
	cout << "str주소를 입력 : ";
	//cin >> str; //공백에서 짤림
	getline(cin, str); //공백포함해서 모두 받음
	//cin.ignore();
	cout << str << endl;


	char ch[10] = { "" };
	cout << "ch주소를 입력 : "; 
	//cin.getline(ch, 10); //맨마지막 문자 NULL로 바꿔서 짤라버림
	cin >> ch; //공백에서 짤림
	cin.ignore();
	cout << ch << endl;

	return 0;
}