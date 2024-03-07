#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string i_file = "";
	string o_file = "";

	cout << "원본 파일 이름 : ";
	cin >> i_file;
	cout << "복사 파일 이름 : ";
	cin >> o_file;

	ifstream source(i_file, ios::binary);
	ofstream dest(o_file, ios::binary);

	if (!source || !dest)
	{
		cerr << "원본 파일 열기 실패" << endl;
		exit(1);
	}
#if 1
	dest << source.rdbuf();
	cout << "#if문 실행" << endl;

#else
	while (!source.eof())
	{
		// 한글자씩 읽어서 느리고, 맨끝에 1바이트로 FF라는 쓰레기 값이 채워진다.
		dest.put(source.get());
	}
	cout << "#else문 실행" << endl;

#endif

	return 0;
}