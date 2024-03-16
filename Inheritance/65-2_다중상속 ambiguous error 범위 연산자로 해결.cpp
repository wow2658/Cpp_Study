#include <iostream>
using namespace std;

class SuperA
{
public : 
	int x;
	void sub()
	{
		cout << "SuperA의 sub() 호출" << endl;
	}
	SuperA()
	{
		this->x = 0;
		cout << "SuperA 기본 생성자 호출" << endl;
	}
	~SuperA() 
	{
		cout << "SuperA 소멸자 호출" << endl;
	}
};

class SuperB
{
public :
	int x;
	void sub() 
	{
		cout << "SuperB의 sub() 호출" << endl;
	}
	SuperB() 
	{
		this->x = 0;
		cout << "SuperB 기본 생성자 호출" << endl;
	}
	~SuperB()
	{
		cout << "SuperB 소멸자 호출" << endl;
	}
};

class Sub : public SuperA, public SuperB
{
public :
	Sub()
	{
		cout << "자식 Sub 기본 생성자 호출" << endl;
	}
	~Sub() 
	{
		cout << "자식 Sub 소멸자 호출" << endl;
	}
};

int main(void)
{

	Sub obj;
	//obj.x = 10;	//양쪽 부모 둘다 똑같은 이름의 x를 가지고 있어서 모호하다(ambiguous)고 오류난다.
	
	//범위 지정자를 명시하면 모호함을 해결할 수 있다.
	obj.SuperA::x = 10;
	cout << obj.SuperA::x << endl;
	obj.SuperB::x = 20;
	cout << obj.SuperB::x << endl;

	//obj.sub();	//함수도 마찬가지이다.
	obj.SuperA::sub();
	obj.SuperB::sub();

	return 0;
}
//개발이 진행될 수록 복잡해져서 모호함을 해결하기 어려워지니 가급적 다중상속은 피하는 것이 좋다.
//오죽하면 Java에서는 다중상속을 막아버렸겠는가?
//차라리 다중상속말고 포함이라는 기능을 사용하는 것을 권장한다.






