#include <iostream>
using namespace std;

class myException
{
private:
	int errorCode;
	char errorMessage[256];
public:
	myException(int errorCode, const char* errorMessage)
	{
		this->errorCode = errorCode;
		strcpy_s(this->errorMessage, 256, errorMessage);
	}
	int getErrorCode() const
	{
		return this->errorCode;
	}
	const char* getErrorMessage() const
	{
		return this->errorMessage;
	}

};

int main(void)
{
	try
	{
		int num = 0;
		cout << "양의 정수를 입력하세요 : ";
		cin >> num;

		if (num < 0)
		{
			myException ex(10, "양의 정수를 입력해주세요.");
			throw ex;
		}
		cout << "입력한 정수 값은 " << num << "입니다.";
	}
	catch (myException& ex)
	{
		cout << "ErrorCode : [" << ex.getErrorCode() << "]\n";
		cout << "예외 메시지 : " << ex.getErrorMessage() << "\n";
	}
	return 0;
}