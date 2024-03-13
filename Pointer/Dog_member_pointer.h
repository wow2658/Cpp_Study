#pragma once
#include <iostream>
#include <string>
using namespace std;

class Dog
{
private:
	int* pWeight;
	int* pAge;
public:
	Dog() : pWeight{ new int{10} }, pAge{ new int(1) }				//괄호 {10} (1) 둘다 유효하다. 역시 생성자 초기화는 여기에서!
	{
		cout << "생성자 호출" << endl;
		//this->pAge = new int(1); this->pWeight = new int{ 10 };	//이쪽도 마찬가지로 괄호 {10} (1) 둘다 유효하다.
		cout << "this는 주소를 지닌 포인터인가? 생성자에서 : " << this << endl;
	}
	~Dog()
	{
		cout << "소멸자 호출" << endl;
		//생성자에서 동적 할당했기 때문에 명시적으로 소명자에서 delete 해줘야한다.
		//만약 아래 코드가 없다면 heap에 int 10,1이 차지한 공간이 남아있어
		//메모리 누수 현상이 발생한다.
		delete this->pWeight;
		delete pAge;
		//heap에 int 10,1이 차지한 공간 날아간것 확인


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