#include <iostream>
using namespace std;

void func1();
void func2();
void func3();
int main(void)
{
	try
	{
		func3();
	}
	catch (int e)
	{
		cout << "예외 발생, " << e << "가 throw되었음.\n";
	}
	return 0;
}
// 부모와 자식 생성자 순서 관련해서 호출과 실행은 다르다고 말했던 것을 복습해보자.
void func1()
{
	//try // 이쪽에 try이 한게 아니라서 main으로 점프하게 되면 스택 쌓였던게 싹 날아가고 종료되는것 같다.
	//{
	//	cout << "func1() 실행\n";
	//}
	//catch (int e)
	//{
	//	throw 0;
	//}
	throw 0;
	cout << "func1() 실행\n";
}

void func2()
{
	func1();
	cout << "func2() 실행\n";
}

void func3()
{
	func2();
	cout << "func3() 실행\n";
}