#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream os("08-2_result.txt");
	char ch = ' ';

	while (cin.get(ch))
	{
		os.put(ch);
	}

	cout<<"파일이 저장되었습니다.";

	return 0;
}