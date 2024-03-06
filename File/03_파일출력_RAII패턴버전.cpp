#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	// 귀찮게 일일히 \\으로 붙여줘야한다.
	ofstream os("test.txt");

	if (!os)
	{
		cerr << "에러" << endl;
		exit(1);
	}

	for (int i = 0; i < 100; i++)
	{
		os << i << " ";
	}

	//RAII 패턴을 이용하면 open fail clo
	return 0;
}