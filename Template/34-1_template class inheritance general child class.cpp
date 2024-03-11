#include <iostream>
using namespace std;

// 부모 : 템플릿 클래스 -> 자식: 일반 클래스인 경우의 상속. <int>처럼 부모 자료형을 확정하고 상속시켜야 한다. 20줄 확인 
template <typename T>
class Parent
{
private:
	T result1;

public:
	Parent(T result1) : result1(result1) // this->result1에 초기화
	{}
	void showResult1()
	{
		cout << this->result1 << endl;
	}
};

class child : public Parent<int>
{
private:
	int result2;

public:
	child(int result1, int result2) : Parent<int>(result1) 	// 부모생성자(파라미터 한개받는 버전) 호출
									, result2(result2) // this->result2에 초기화
	{}
	void showResult2()
	{
		cout << this->result2 << endl;
	}
};

int main(void)
{
	child child(100,500);

	child.showResult1();
	child.showResult2();
	return 0;
}