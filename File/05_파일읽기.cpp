#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
	ifstream is("���\\noRAII.txt", ios::in);

	if (!is)
	{
		cerr << "���� ���� ����" << endl;
		exit(1);
	}


	// �ѱ��ھ� �ҷ����� ����
	//char ch = ' ';
	//int cnt = 0;
	//while (is)
	//{
	//	is.get(ch);
	//	cout << ch;
	//	++cnt;
	//}

	// ���پ� �ҷ����� ����
	string str = "";
	int cnt = 0;
	while (is)
	{
		getline(is, str); //#include <string> �ʿ�
		cout << str;
		++cnt;
	}


	cout << endl;

	cout << "�� ���� �� : " << cnt << endl;
	cout << "���� �б� ����" << endl;


	return 0;
}