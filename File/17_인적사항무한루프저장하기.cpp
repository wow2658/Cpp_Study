#include "user.h"

int main(void)
{
	User user[50];

	int num = 0;
	string name;
	string tel;
	string email;

	ofstream os("USER.txt");
	if (!os)
	{
		cerr << "USER.txt파일 오픈 실패" << endl;
		exit(1);
	}

	char ext = ' ';
	while (true)
	{
		cout << "당신의 순번은 " << num+1 << "번 입니다.\n";
		cout << "이름을 입력하세요 : ";
		cin >> name;
		cout << "전화번호를 입력하세요 : ";
		cin >> tel;
		cout << "이메일을 입력하세요 : ";
		cin >> email;

		user[num].set_user(num+1, name, tel, email);

		// 찾고 싶은 숫자로 0을 부르는 일이 잘 없을테니까
		// 그렇다고 배열의 0번 인덱스를 비워버리면 메모리 낭비이고
		os << num+1 << "\t\t" << name << "\t\t" << tel << "\t\t" << email<<endl;

		cout << "종료 하시겠습니까? (Y/N) : ";
		cin >> ext;
		if ('Y' == ext || 'y' == ext) break;

		user[num].printUser();
		++num;
	}

	// 이 부분을 간과하면 오류나기 십상이다.
	int serchNum = 0;
	cout << "찾고 싶은 번호를 입력하세요 : ";
	cin >> serchNum;

	for (int i = 0; i <= num; ++i)
	{
		if (user[i].getNum() == serchNum)
		{
			user[i].printUser();
		}
	}
	 
	 return 0;
}