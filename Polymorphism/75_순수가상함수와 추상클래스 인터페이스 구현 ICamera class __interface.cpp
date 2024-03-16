//C++에서는 interface 키워드를 제공하지 않는다고 74_에서 언급한 바가 있다.
//하지만 없으면 만들어서라도 사용하면 그만이다.
//추상 클래스 안에 순수 가상함수만 넣어서 각각 다른 자식 클래스에 다른 기능을 하게끔
//만들어 주는 기법이 있다.

#include <iostream>
using namespace std;

//직접 구현해보기 전에! 가볍게 참고
//C++자체에서는 없지만 MSVC(MicroSoft Visual C++)컴파일러에는 __interface 키워드가 존재한다.
//__interface 키워드는 비주얼 스튜디오 MSVC에서만 사용 가능하므로 다른 개발환경에서는 주의하자.

class ICamera // 이 친구는 void display() {} 에게 이상함을 못느끼지만
//__interface ICamera // 이 친구는 virtual 안 붙어있다고 바로 오류를 내주는 기능이 추가되어있다.
{
public:

	virtual void take() = 0;
	virtual void on() = 0;
	virtual void off() = 0;
	void display() {}
};

class NormalCarmera : public ICamera
{
public:

	virtual void take() override
	{
		cout << "Normal Carmera Shot" << endl;
	}
	virtual void on() override
	{
		cout << "Normal Carmera on" << endl;
	}
	virtual void off() override
	{
		cout << "Normal Carmera off" << endl;
	}
};


class NikkonCamer : public ICamera
{
public:
	virtual void take() override
	{
		cout << "Nikkon Carmera Shot" << endl;
	}
	virtual void on() override
	{
		cout << "Nikkon Camera on" << endl;
	}
	virtual void off() override
	{
		cout << "Nikkon Camera off" << endl;
	}
};

class People
{
public:

	void useCamera(ICamera* p)
	{
		p->take();
	}
	void cameraOn(ICamera* p)
	{
		p->on();
	}
	void cameraOff(ICamera* p)
	{
		p->off();
	}
//ICamera를 매개변수에 넣은 의도를 그동안 배워온 다형성과 연결하여 생각해보자
//일단 ICamera 본인 스스로는 인스턴스를 생성하지 못하는 상태이므로
//매개변수에 들어올 수 있는 클래스를 ICamera의 자식클래스로만 가려 받겠다.
// + 그냥 상속만 받은 쭉정이가 아니라 순수가상함수를 재정의까지한 자식으로 받겠다.
// + 들어오는 순간 업캐스팅 해버리겠다. 그러면 virtual override도 해놓은 자식이어야한다.
//People은 호출만 하면되고 디테일한 동작 구현은 ICamera 계열들에게 알아서 맡기면 그만이기 때문에
//아주 편해진다. 

};

int main(void)
{
	//멤버함수인 useCamera()을 사용하기 위해서 인스턴스를 생성함
	People people;

	//NormalCarmera nc;
	//people.useCamera(&nc);
	NormalCarmera* nc = new NormalCarmera();
	people.cameraOn(nc);
	people.useCamera(nc);
	people.cameraOff(nc);
	cout << endl << endl;

	//NikkonCamer ni;
	//people.useCamera(&ni);
	NikkonCamer* ni = new NikkonCamer();
	people.cameraOn(ni);
	people.useCamera(ni);
	people.cameraOff(ni);

	delete nc;
	delete ni;

	return 0;
}
