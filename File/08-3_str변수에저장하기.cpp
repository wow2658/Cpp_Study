#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string address = "";
	cout << "주소를 입력하세요 : ";
	getline(cin, address);

	ofstream os("08-3_result.txt"); //#include <fstream> 필요
	if (!os)
	{
		cerr << "파일을 열 수 없습니다." << endl;
		return 1;
	}

	if (!address.empty())
	{
		os << "나는 " << address << "에서 살고 있습니다." << endl;
		cout << "파일이 저장되었습니다.";
	}
	else
	{
		cout << "주소가 입력되지 않았습니다. 파일에 저장되지 않았습니다." << endl;
	}
	return 0;
}