#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

const int SIZE = 10;

int main(void)
{
#if 0
	// C 스타일
	FILE* fp = nullptr;
	fopen_s(&fp, "random.dat", "r");
	fseek(fp, 0, SEEK_END);
	int byte_size = ftell(fp);
	cout << "파일의 크기 : " << byte_size << endl;
	fclose(fp);
#endif

	int data = 0;

	ofstream os("random.dat", ios::binary);
	if (!os)
	{
		cerr << "파일 열기 실패" << endl;
		exit(1);
	}

	// 파일에 난수 저장
	for (int i = 0; i < SIZE; i++)
	{
		data = rand();
		cout << data << " ";
		os.write((char*)&data, sizeof(int));
	}
	os.close(); // 이거 안써주면 밑에서 size가 계속 0으로 나온다.
	//os.seekp(0, ios::beg); 이걸 쓰던가
	/*
	이 코드에서 size가 0으로 나오는 이유는 
	파일에 쓰기를 한 후에 파일 포인터를 다시 파일의 시작점으로 이동시키지 않았기 때문입니다.
	파일에 쓰기를 하면 파일 포인터는 파일의 끝에 위치하게 되므로, 
	그 상태에서 파일의 크기를 구하려고 하면 0이 나옵니다.
	따라서 파일에 쓰기를 한 후에는 os.seekp(0, ios::beg); 와 같이 
	파일 포인터를 파일의 시작점으로 이동시켜야 합니다.
	그러면 파일의 크기를 정상적으로 구할 수 있습니다.
	*/

	ifstream is("random.dat", ios::binary);
	if (is.fail())
	{
		cerr << "파일 열기 실패" << endl;
		exit(1);
	}

	// 끝에 도달해서 파일 크기 알아내기
	is.seekg(0, ios::end);
	long size_ = is.tellg();
	cout << endl << "파일 크기 : " << size_ << "byte" << endl;

	cout << "\n";

	// 파일 중앙으로 이동한 후 읽기
	is.seekg(size_ / 2, ios::beg);
	is.read((char*)&data, sizeof(int));
	cout << "중앙에 위치한 값 : " << data << endl;

	cout << "\n";

	// 파일의 처음 위치로 이동
	is.seekg(0, ios::beg);
	cout << "파일 표시 위치자 현재 값 : " << is.tellg() << endl;
	is.read((char*)&data, sizeof(int));
	cout << "파일의 시작위치에 있는 값 : " << data << endl;

	cout << "\n";

	// 파일의 끝 위치로 이동, 값이 루프되는 것을 확인
	is.seekg(0, ios::end);
	cout << "파일 표시 위치자 현재 값 : " << is.tellg() << endl;
	is.read((char*)&data, sizeof(int));
	cout << "파일의 시작위치에 있는 값 : " << data << endl;

	cout << "\n";

	// 파일의 끝위치에서 한칸 앞으로(왼쪽) 이동
	is.clear(); // 플래그 초기화, 이거 안해주면 
	/*
	is.seekg(-4, ios::end) 이 부분이 - 1이 나오는데 이유는 
	파일의 끝에 도달한 후에는 eofbit이라는 플래그가 켜지기 때문입니다.
	이 플래그는 파일의 끝에 도달했다는 의미로, 
	이 상태에서는 seekg나 read와 같은 입출력 함수가 
	작동하지 않습니다.
	따라서 파일의 끝에 도달한 후에는 clear() 함수를 호출하여 플래그를 초기화해주어야 합니다.
	그러면 다시 seekg나 read 함수를 사용할 수 있습니다.*/

	is.seekg(-4, ios::end);
	cout << "파일 표시 위치자 현재 값 : " << is.tellg() << endl;
	is.read((char*)&data, sizeof(int));
	cout << "파일의 시작위치에 있는 값 : " << data << endl;

	cout << "\n";
	return 0;
}
