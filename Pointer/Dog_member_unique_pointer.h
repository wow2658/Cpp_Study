#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Dog
{
private:
	unique_ptr<int> pWeight;
	unique_ptr<int> pAge;
public:
	Dog() : pWeight(make_unique<int>(10)), pAge(make_unique<int>(1))	// { { } } 안됨, ( { } ) 안됨
	{
		cout << "생성자 호출" << endl;
		//this->pAge = new int(1); this->pWeight = new int{ 10 };	//이쪽도 마찬가지로 괄호 {10} (1) 둘다 유효하다.
		cout << "this는 주소를 지닌 포인터인가? 생성자에서 : " << this << endl;
	}
	~Dog()
	{
		cout << "소멸자 호출" << endl;

		pWeight.reset();
		pAge.reset();

		//unique_ptr로 구현했으면 안해도 됐을텐데 실험해보자.
		cout << "pWeight가 가지고 있는 주소값 소멸자에서 : " << this->pWeight << endl;
		cout << "pAge가 가지고 있는 주소값 소멸자에서 : " << pAge << endl;
		cout << "this가 가지고 있는 주소값 소멸자에서 : " << this << endl;

	}
public:
	int getWeight()
	{
		//return *pWeight;
		return *(this->pWeight);
	}
	int getAge()
	{
		return *pAge;
		//return *(this->pAge);
	}
	void setWeight(int weight)
	{
		//*pWeight = weight;
		*(this->pWeight) = weight;
	}
	void setAge(int age)
	{
		*pAge = age;
		//*(this->pAge) = age;
	}
};