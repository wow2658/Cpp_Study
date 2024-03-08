#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str ="";
	cout << "가위, 바위, 보 게임입니다.: "<<endl;
	try
	{
		cout << "무엇을 내시겠습니까? : ";
		cin >> str;;
		if ("가위"!= str && "바위" != str && "보" != str)
		{
			throw "\"가위\", \"바위\", \"보\" 중에서만 선택해주세요.";
		}
	}
	catch (const char* message)
	{
		cout << "예외 발생 : " << message << endl;
	}
	cout<<"당신은 "<<str <<"을 내셨습니다." << endl;

	return 0;

}
