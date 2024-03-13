#pragma once
#include <iostream>
#include <string>
using namespace std;

class Monster
{
private:
	string name;
	double hp;
	double damage;
public:
	Monster(string _name, double _hp, double _damage) :
		name(_name), hp(_hp), damage(_damage) //? 여기에서는 this-> 가 오류가 난다.
	{
		//? 여기에서는 this-> 괜찮은데

		/*!!!
		C++에서 생성자 초기화 리스트에서 this->를 사용할 수 없는 이유는,
		'초기화 리스트'가 객체의 멤버 변수들이 실제로 생성되기 전에 실행되기 때문이다.
		'초기화 리스트'는 멤버 변수들에 대한 초기값을 설정하는 곳이며,
		this 포인터가 아직 멤버 변수들을 가리킬 수 있는 상태가 아니다.
		!!!*/

		//! 생성자() : "위에 저 부분을 '초기화 리스트' 라고 하는구나". 지식을 얻었다~//
	}
	~Monster()
	{
		cout << this->name << "의 소멸자 호출" << endl;
	}
	void printMonsterInfo();
};

void Monster::printMonsterInfo()
{
	cout << "몬스터 이름 : " << this->name << endl;
	cout << "몬스터 체력 : " << this->hp << endl;
	cout << "몬스터 공격력 : " << this->damage << endl;
}