#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream is("scores.txt");
	ofstream os("10_result.txt");

	if (is.fail())
	{
		cerr<< "scores.txt 파일 열기 실패" <<endl;
		exit(1);
	}
	if (os.fail())
	{
		cerr << "10_result.txt 파일 열기 실패" << endl;
		exit(1);
	}

	int line = 1; os << line << ": ";

	char ch = ' '; 	is.get(ch);
	while (!is.eof())
	{
		os<<ch;

		if ('\n' == ch)
		{
			++line;
			os << line <<": ";
		}

		is.get(ch);
	}

	return 0;
}