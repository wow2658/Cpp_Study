#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int main(void)
{
	string i_file = "";
	string o_file = "";

	cout << "원본 파일 이름 : "; // 경로 \\ 두번쳐줘야한다.
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
	clock_t start;
	clock_t end;

	int buffer[4096] = {0};

	start = clock();
#if 0
	dest << source.rdbuf();
	cout << "#if문 실행" << endl;

#else
	while (!source.eof())
	{
		// 한글자씩 읽어서 제일 느리고, 맨끝에 1바이트로 FF라는 쓰레기 값이 채워진다.
		//dest.put(source.get());

		source.read( (char*)&buffer, sizeof(buffer));
		dest.write( (char*)&buffer, sizeof(buffer));
	}
	cout << "#else문 실행" << endl;

#endif
	end = clock();
	cout << "파일 복사 완료" << endl;

	cout << "CLOCKS_PER_SEC : " << CLOCKS_PER_SEC << endl;
	cout << "CPU-TIME START : " << start << endl;
	cout << "CPU-TIME END : " << end << endl;
	cout << "CPU-TIME END - START : " << end - start << endl;
	cout << "파일 복사 시간 : " << static_cast<double> (end - start) / CLOCKS_PER_SEC << endl;
	
	return 0;

	// 300MB 파일 복사 비교
	// rdbuf() 사용				: 9.859초
	// while .put(.get())사용	: 59.871초
	// buffer[100] 사용			: 1.241초
	// buffer[4096] 사용			: 0.562초
}