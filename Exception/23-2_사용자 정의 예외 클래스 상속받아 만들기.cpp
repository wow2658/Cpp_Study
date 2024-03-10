#include <iostream>
#include <string>
#include <exception>

using namespace std;

// 사용자 정의 예외 클래스중 what()을 활용하기 위해서 exception(예외의 최고 부모클래스)을 부모로 상속받자.
class ChildException : public exception
{
public:
// 부모클래스인 exception에 있는 what()을 재정의(오버라이딩)
	const char* what() const noexcept override
	{
		return "자식클래스 예외 발생";
	}
};

int main(void)
{
	try
	{
		throw ChildException();
	}
	catch (exception& e)
	{
		cout << typeid(e).name() << endl;
		cerr << e.what() << endl;
	}
}