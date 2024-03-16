#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal 
{
public:
	virtual void speak() = 0;
	virtual ~Animal() {};
};

class Dog : public Animal 
{
public:
	virtual void speak() 
	{
		cout << "멍!" << endl;
	}
};

class Cat : public Animal 
{
	virtual void speak() 
	{
		cout << "꽹!" << endl;
	}
};

int main(void) 
{
	vector<Animal*> barn;

	barn.push_back(new Dog());	
	barn.push_back(new Cat());
	barn.push_back(new Cat());

	//for (auto& a : barn) 
	for (Animal* a : barn) 
	{
		a->speak();
		cout << "주소 : " << a << endl;
	}
	barn.clear();	
	//Dog에 맞는 barn따로 만들고, Cat에 맞는 barn따로 만들고
	//또 나중에 돼지나 소가 추가 됐을 때 또 거기에 맞는 barn 선언해서 만드는 주먹구구 식으로
	//작업하는 것은 매우 비효율적이기 때문에 위와 같이 Animal하나로 다 품어버리는 것이
	//다형성의 또 다른 장점이자 적절한 사용법이다.
	//구글에 한글로 다형성을 검색했을때 대다수 블로그들이 위의 것에 대해 언급이 아예 없거나
	//그냥 글로만 설명하고 직접적인 예시는 없어서 이해가 될듯말듯 한 상태에 머물러 답답했었다.
	//https://blogshine.tistory.com/68 에서 참 잘 설명해줘서 많은 도움이 됐다.

	//여담이지만, 예전에 언리얼 프로젝트에서 enemy를 오브젝트풀을 통해 관리했었는데
	//enemy의 종류마다 오브젝트풀을 전부 따로 만들어야 했었다.
	//이번에 배운 다형성을 이용하면 enemy를 종류 상관없이 한번에 관리하는
	//방법도 구현이 가능하겠구나 하는 실마리를 얻게되어 재미있었다.

	vector<int> int_var;
	int_var.push_back(10);
	int_var.push_back(10.9);
	for (int& a : int_var)
	{
		cout << a << endl;
	}
	vector<string> string_var;
	string_var.push_back("언");
	string_var.push_back("리");
	string_var.push_back("얼");
	for (string a : string_var) 
	{
		cout << a << endl;
	}

	return 0;
}

