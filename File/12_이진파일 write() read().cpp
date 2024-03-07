#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int buffer[] = { 10,20,30,40,50 };

	ofstream os("test.dat", ios::binary);
	ifstream is("test.dat", ios::binary);

	if (!os)
	{
		cerr << "test.dat 파일 열기 실패" << endl;
		exit(1);
	}
	if (!is)
	{
		cerr << "test.dat 파일 열기 실패" << endl;
		exit(1);
	}

	os.write( (char*)&buffer, sizeof(buffer));
	cout << sizeof(buffer) << endl;
	// .dat 파일은 powershell에서 "Format-Hex 경로\경로\" 명령어로 열어서 확인할 수 있다.
	// \는 한번만 쓰면 된다.



	is.read((char*)&buffer, sizeof(buffer));
	for (auto& e : buffer)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;
}