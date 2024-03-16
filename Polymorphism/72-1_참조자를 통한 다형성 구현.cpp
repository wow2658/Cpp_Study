//참조자(별명, 주소를 가진 &)도 포인터와 마찬가지로 다형성을 구현할 수가 있다.

#include <iostream>
using namespace std;


class Person
{
public:

	virtual void speak()
	{
		cout << "Person speak()" << endl;
	}
	~Person()
	{
		cout << "Person 소멸자 호출" << endl;
	}
};

class Student : public Person
{
public:

	virtual void speak() override
	{
		cout << "Student speak()" << endl;
	}
	~Student()
	{
		cout << "Student 소멸자 호출" << endl;
	}
};

class Worker : public Person
{
public:

	virtual void speak() override
	{
		cout << "Worker speak()" << endl;
	}
	~Worker()
	{
		cout << "Worker 소멸자 호출" << endl;
	}
};

int main(void)
{

	Student student;
	Person person1 = student; //복사 생성자가 호출된다.
	person1.speak();		  //student의 speak()를 호출하려는 다형성 의도 실패

	cout << "student 주소 : " << &student << endl;
	cout << "person1 주소 : " << &person1 << endl;

	cout << endl << endl;

	Person& person2 = student; //복제가 아니라 직접 넘어간다.
	person2.speak();		   //student의 speak()를 호출하려는 다형성 의도 성공

	cout << "student 주소 : " << &student << endl;
	cout << "person2 주소 : " << &person2 << endl;

	cout << endl << endl;

	Worker worker;
	Person person3 = worker;

	person3.speak();

	cout << "worker 주소 : " << &worker << endl;
	cout << "person3 주소 : " << &person3 << endl;

	cout << endl << endl;
	Person& person4 = worker;

	person4.speak();

	cout << "worker 주소 : " << &worker << endl;
	cout << "person4 주소 : " << &person4 << endl;

	return 0;
}






