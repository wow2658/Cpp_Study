#include <iostream>
using namespace std;

// 부모 : 템플릿 클래스 -> 자식: 템플릿 클래스인 경우의 상속. <int>처럼 부모 자료형을 확정하고 상속시켜야 한다. 20줄 확인 
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
	void addResult1(T result2)
	{
		this->result1+=result2;
	}
};

template <typename U> //T다음이 U라서 이것을 애용하는듯
class Child : public Parent<U>
{
private:
	U result2;

public:
	Child(U result1, U result2) : Parent<U>(result1) 	// 부모생성자(파라미터 한개받는 버전) 호출
		, result2(result2) // this->result2에 초기화
	{}
	void exchange()
	{
		this->addResult1(this->result2); // this-> 붙여줘야 컴파일 통과가능
		this->result2 =0;
	}
};

int main(void)
{
	Child<int> child(1000, 5000);
	Child<double> child2(10.55, 50.55);

	child.exchange();
	child.showResult1();

	child2.exchange();
	child2.showResult1();
	return 0;
}