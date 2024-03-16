//다형성(Polymorphism) : 부모 클래스의 포인터로 자식 클래스의 인스턴스를 다룰 수 있는 성질
//다형성의 대표적인 예로는 함수 오버로딩, 연산자 중복정의가 있었다.
//위의 둘은 컴파일 시간 다형성에 속한다.
//이번에는 실행 시간(런타임) 다형성에 대해 알아보도록 하자.

//런타임 다형성이란? 객체들의 타입이 다르면 똑같은 메세지를 보내더라도 서로 다른 동작을 하는 것을 말하는데
//상속을 전제조건으로하고 객체 포인터를 통하여 이루어진다.
//말만으로는 전혀 감이 안잡힌다.

#if 0
#include <iostream>
using namespace std;

class Animal
{
public:
	void speak()
	{
		cout << "Animal Speak() 호출" << endl;
	}
};

class Dog : public Animal
{
public:
	int age;


	{
		cout << "멍" << endl;
	}
};

class Cat : public Animal
{
public:

	virtual void speak() override	//C++에서는 딱히 쓰지않아도 오류가 나진 않는다. 그래도 가독성을 위해 쓰자.
	{
		cout << "냥" << endl;
	}
};

int main(void)
{
	//아래는 업캐스팅인데 다운캐스팅보다 이해하기 쉽다.
	Animal* ani1 = new Dog();
	ani1->speak();		//Dog라서 멍을 기대했는데 아직 부모 Animal의 Speak()가 출력.

	cout << endl;

	Animal* ani2 = new Cat();
	ani2->speak();		//마찬가지로 냥을 기대했는데 부모 Animal의 Speak()가 출력.

	//? 다형성이 적용안된 이유가 무엇일까?
	//근본이 숏다리인 부모 클래스 Animal에 age 멤버함수는 존재하지 않고
	//자식 클래스에서 구현해놓은 것이기 때문에 닿지않는다. 존재를 모르는 것이다.

	//ani1.age;			//비슷한 원리로 부모 클래스는 자식 클래스의 멤버함수와 멤버변수에 접근할 수 없다는 것을 
						//Inheritance 54_에서 학습했었다.

	cout << endl;

	//아래는 자급자족하는 것인데 규격이 딱 맞아 문제될 것이 없음을 알 수 있다. 
	Dog* dog = new Dog();
	dog->speak(); //멍

	Cat* cat = new Cat();
	cat->speak(); //냥


	
	return 0;
}
#else
//이때 필요한 것이 가상 함수(virtual function)이다. 언리얼에서 상속관련해서 정말 자주 썼던 것이다.
//가상 함수는 다형성을 구현하기 위해서 부모 클래스의 멤버함수에 virtual이란 키워드를 함수 원형 앞에 기입하여
//다형성을 적용시키는 역할을 한다. 오로지 클래스의 멤버함수에만 키워드를 사용할 수 있다는 것을 주의하자.

#include <iostream>
using namespace std;


class Animal
{
private:
	int age;
public:
	Animal(int age = 0)
	{
		this->age = age;
	}

	virtual void speak() //바뀐부분
	{
		cout << "Animal Speak()" << endl;
	}
	virtual int getAge()
	{
		cout << "Animal getAge()" << endl;
		return this->age;
	}

	void addAge(Animal* dog)
	{
		cout << "this->age : " << this->getAge() << endl;
		cout << "dog->age : " << dog->getAge() << endl;
		this->age += dog->getAge();
	}
};

class Dog : public Animal
{
public:
	int age;

	virtual void speak() override	//언리얼에서는 꼭 virtual override를 기입했던것 같은데
	{
		cout << "멍" << endl;
	}
	Dog(int age)
	{
		this->age = age;
		cout << "Dog.age = " << this->age << endl;
	}
	int getAge()					//여기에서는 꼭 안써도 오류가 발생하지는 않는다. 하지만 가독성을 위해서 쓰도록하자.
		{
		cout << "dog getAge()" << endl;
		return this->age;
		}
};

class Cat : public Animal
{
public:
	int age;

	virtual void speak()
	{
		cout << "냥" << endl;
	}
	Cat(int age)
	{
		this->age = age;
		cout << "cat->age : " << this->age << endl;
	}
	virtual int getAge()
	{
		cout << "cat getAge()" << endl;
		return this->age;
	}
};

int main(void)
{

	Animal* ani1 = new Dog(10);
	ani1->speak();		

	cout << endl;

	Animal* ani2 = new Cat(10);
	ani2->speak();	

	cout << endl;

	Animal* ani3 = new Animal(10);
	Dog dog2(20);
	ani3->addAge(&dog2);		//매개변수의 다형성은 반드시 포인터나 참조자를 이용해야한다.
	cout << "ani3->addAge(dog2) : " << ani3->getAge() << endl;

	cout << endl << endl;

	Animal* ani4 = new Animal(20);
	Cat cat2(50);
	ani4->addAge(&cat2);		//매개변수의 다형성은 반드시 포인터나 참조자를 이용해야한다.
	cout << "ani4->addAge(cat2) : " << ani4->getAge() << endl;

	return 0;
}
#endif