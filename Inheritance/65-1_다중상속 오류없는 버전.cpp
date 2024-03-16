#include <iostream>
using namespace std;

class PassaengerCar 
{
public :
	int seats;	
	void set_seats(int seats) 
	{
		this->seats = seats;
	}
	PassaengerCar()
	{
		this->seats = 0;
		cout << "PassaengerCar 기본 생성자 호출" << endl;
	}
	~PassaengerCar() 
	{
		cout << "PassaengerCar 소멸자 호출" << endl;
	}	
};
class Truck 
{
public :
	int payLoad;	//적재하중
	void set_payLoad(int payLoad) 
	{
		this->payLoad = payLoad;
	}
	Truck() 
	{
		this->payLoad = 0;
		cout << "Truck 기본 생성자 호출" << endl;
	}
	~Truck()
	{
		cout << "Truck 소멸자 호출" << endl;
	}
};

class Pickup : public PassaengerCar, public Truck 
{
public :
	int tow_capability;		//견인능력
	void set_tow_capability(int tow_capability) 
	{
		this->tow_capability = tow_capability;
	}
	Pickup()
	{
		this->tow_capability = 0;
		cout << "Pickup 기본 생성자 호출" << endl;
	}
	~Pickup()
	{
		cout << "Pickup 소멸자 호출" << endl;
	}
	void printPickup() 
	{
		cout << "정원 : " << this->seats << ", 적재하중 : " << this->payLoad << ", 견인능력 : " <<
			this->tow_capability << endl;
	}
};

int main(void) 
{

	Pickup my_car;
	my_car.set_seats(4);
	my_car.set_payLoad(1000);
	my_car.set_tow_capability(30000);
	my_car.printPickup();
	return 0;
}
//이름이 똑같아서 충돌나는 멤버변수나 멤버함수가 없으니 문제점이 발생하지 않았다.
//현실에서 이렇게 깔끔하기는 어렵지않을까?