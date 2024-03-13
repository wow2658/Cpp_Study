//몇명의 이름을 저장하시겠습니까? : 3
//이름 입력 # 1 : 김민지
//이름 입력 # 2 : 강해린
//이름 입력 # 3 : 팜하니
//저장된 이름 목록입니다.
//이름 #1 : 김민지
//이름 #2 : 강해린
//이름 #3 : 팜하니
#include <iostream>
#include <string>
using namespace std;

int main(void)
{

	int length = 0;
	cout << "몇명의 이름을 저장하시겠습니까? : ";
	cin >> length;

	string* names = new string[length];

	for (int i = 0; i < length; i++) {
		cout << "이름 입력 # " << i + 1 << " : ";
		cin >> names[i];
	}
	cout << endl << endl;
	cout << "저장된 이름 목록입니다." << endl;
	for (int i = 0; i < length; i++) {
		cout << "이름 #" << i + 1 << " : " << names[i] << endl;
	}
	delete[] names;
	names = nullptr;

	return 0;
}
