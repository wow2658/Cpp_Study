#include <iostream>
#include <string>
#include "Box_template_class.h"

using namespace std;

template <typename T1, typename T2>
class Person
{
private:
	//T1 first;
	T2 second;
public:
	T1 first;
	T1 get1();
	T1* get1addr();
	T2 get2();
	void set1(T1 first);
	void set2(T2 second);

};

int main(void)
{
	Person<int, string> p1;
	p1.set1(31);
	p1.set2("김성태");
	cout << "나이 : " << p1.get1() << ", 이름 : " << p1.get2() << endl;

	Person<double, string> p2;
	p2.set1(96.0123);
	p2.set2("얍얍");
	cout << "닉네임 : " << p2.get2() << ", 평균 : " << p2.get1() << endl;

	cout << "\n\n";
	#if 0
	Box<int> box{}; //이렇게 정의하면 어떤 오류가 일어날까??
	Person<Box<int>, string> p3; // 박스를 두번 정의해버리게 된다!
	p3.set1(box);
	p3.set2("얍마이무");

	cout << "box의 주소 : " << &box << endl;						//어쩌구저쩌구F784 (주소는 어차피 실행할때마다 바뀐다)
	cout << "Person안의 box주소 : " << &p3.first << endl;		//어쩌구저쩌구F7D0 (first를 잠시 public에 놨을때)
	cout << "Person안의 box주소 : " << p3.get1addr() << endl;	//어쩌구저쩌구F7D0 (box 두개나 만들어져 버리니 나중에 setData로 호출할때 모호해진다.)


	p3.get1().setData(55);

	//cout << "((오류나는 곳))box의 데이터 값 : " << p3.get1().getData() << ", 리액션 :  " << p3.get2() << endl;
	cout << "box의 데이터 값 : " << p3.get1().getData() << ", 리액션 :  " << p3.get2() << endl;
	cout << "box의 데이터 값 : " << box.getData() << ", 리액션 :  " << p3.get2() << endl;
	#endif
	Box<int>* box = new Box<int>();
	Person<Box<int>*, string> p3; 
	p3.set1(box);
	p3.set2("얍마이무");

	cout << "box의 주소 : " << &box << endl;				

	p3.get1()->setData(55);

	// 이제야 0이 아니라 제대로 set된 data값이 나온다
	cout << "box의 데이터 값 : " << p3.get1()->getData() << ", 리액션 :  " << p3.get2() << endl;

	return 0;
}

template<typename T1, typename T2>
T1 Person<T1, T2>::get1()
{
	return this->first;
}

template<typename T1, typename T2>
T1* Person<T1, T2>::get1addr()
{
	return &this->first;
}

template<typename T1, typename T2>
T2 Person<T1, T2>::get2()
{
	return this->second;
}

template<typename T1, typename T2>
void Person<T1, T2>::set1(T1 first)
{
	this->first = first;
}

template<typename T1, typename T2>
void Person<T1, T2>::set2(T2 second)
{
	this->second = second;
}

