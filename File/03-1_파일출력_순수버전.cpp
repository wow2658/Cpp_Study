#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ofstream os;
	os.open("noRAII.txt");

	if (os.fail())
	{
		cerr << "���� ���� ����" << endl;
		exit(1);
	}

	for (int i = 0; i < 100; i++)
	{
		os << i << " ";
	}

	os.close();

	return 0;
}