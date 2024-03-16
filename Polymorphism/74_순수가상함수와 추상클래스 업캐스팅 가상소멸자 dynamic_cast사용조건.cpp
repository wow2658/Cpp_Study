//가상함수에는 2가지 종류가 있다.
//1. 일반(단순)가상함수 : virutal void print() {} // 이전에 다뤘던 것들이다.
//2. 순수가상함수 : virtual void print() = 0;		// 언리얼에서 부모 클래스나, 공격 인터페이스 헤더파일에서 써봤었다. 

//클래스에서 순수가상함수(추상메서드)가 하나라도 존재하면 그 클래스는 추상클래스(abstract class)라고 한다.
//추상 클래스는 인스턴스를 생성할 수 없고 이것을 상속한 자식 클래스는 인스턴스를 생성하고 싶으면 반드시
//부모에서 = 0; 으로 끝내버린 순수가상함수를 구현해야한다. 구현하지 않아도 인스턴스를 생성 못 할 뿐 오류가 발생하고 그러진 않는다.  

//언리얼에서는 잘 쓰이긴 하지만 C++에서는 interface 키워드를 제공하지 않는다. 
//inferface이란 상수(static fianl), 추상 메서드로만 구성된 자료이다.

#include <iostream>
#include <string>
using namespace std;

class Shape 
{
protected:
	int x;
	int y;
public:
	Shape(int x, int y) : x(x), y(y) {}
	

	virtual void draw() = 0; //<- 순수가상함수 등장


	//~Shape()
	virtual ~Shape()
	{
		cout << "Shape 소멸자 호출" << endl;
	}
};

class Rect : public Shape
{
private:
	int width;
	int height;
public:
	Rect(int x, int y, int width, int height) : Shape(x, y), width(width), height(height) {}

	virtual void draw() override
	{
		cout << "사각형 그렸다. 순수가상함수 재정의 했으니까 이제 인스턴스 만들게 해주세요." << endl;
	}
	virtual void func()
	{
		cout << "func()" << endl;
	};
	~Rect()
	{
		cout << "Rect 소멸자 호출" << endl;
	}

};

int main(void) 
{
	//draw()로 인해 추상 클래스가 되어버린 Shape는 아래와 같이 인스턴스를 생성할 수 없다.
	//Shape* shape = new Shape(1, 2);
	
	//virtual void draw() override로 재정의하기 전에는 오류가 났음을 확인할 수 있었다.
	Shape* shape = new Rect(1, 2, 10, 20);		//업캐스팅
	shape->draw();
	
	//dynamic_cast 쓰고 싶으면 반드시 가상함수가 있는 다형 클래스여야 한다고 70_에서 학습했었다.
	Rect* rect = dynamic_cast<Rect*>(shape);	//Rect를 Shape으로 해석하는 업캐스팅했던 녀석을 Rect로 딱맞게 해석하기
	rect->func();

	cout << shape << " " << rect << endl;		//같은 주소를 가리킨다.
	delete rect;
	//delete shape;								//얕은복사에서 봤던 오류 발생! 둘중 하나만 하자
												//가상 소멸자도 꼭 챙겨주자. 업캐스팅 하면 가상 소멸자를 늘 떠올리도록 연습하자.

	return 0;
}
