#include <iostream>
#include <string>
using namespace std;

class Emplyee 
{
private:
	string name;
	int salary;
public:
	Emplyee(string name = "", int salary = 0)
	{
		this->name = name;
		this->salary = salary;
	}
	string getName() const
	{
		return this->name;
	}
	int getSalary() const
	{
		return this->salary;
	}
	void setName(string name) 
	{
		this->name = name;
	}
	void setSalary(int salary) 
	{
		this->salary = salary;
	}
	int computeSalary() const
	{
		return this->getSalary();
	}
};


class Manager : Emplyee 
{
private:
	int bonus;
public:
	Manager(string name, int salary, int bonus) : Emplyee(name, salary) 
	{
		this->bonus = bonus;
	}
	int getBonus() const
	{
		return this->bonus;
	}
	void setBonus()
	{
		this->bonus = bonus;
	}
	int computeSalary() const //오버라이딩
	{
		return this->bonus + this->getSalary();
	}
	
	void print()
	{
		cout << "이름 : " << this->getName() << endl;
		cout << "월급 : " << this->getSalary() << endl;
		cout << "보너스 : " << this->getBonus() << endl;
		cout << "전체 급여 : " << this->computeSalary() << endl;
	}
};

int main(void)
{

	Manager manager("손석구", 200, 100);
	manager.print();
	//cout << "전체 급여 : " << manager.computeSalary() << endl;
	//main은 최대한 간결하게. 객체지향의 특성을 살리고 가독성을 위해서 적절한 곳에 분배시키는게 좋다. 
	return 0;
}