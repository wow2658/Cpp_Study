#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	// ������ ������ \\���� �ٿ�����Ѵ�.
	ofstream os("test.txt");

	if (!os)
	{
		cerr << "����" << endl;
		exit(1);
	}

	for (int i = 0; i < 100; i++)
	{
		os << i << " ";
	}

	//RAII ������ �̿��ϸ� open fail clo
	return 0;
}