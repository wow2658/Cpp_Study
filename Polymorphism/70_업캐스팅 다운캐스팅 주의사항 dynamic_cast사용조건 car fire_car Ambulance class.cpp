//업캐스팅 : 자식타입을 부모타입으로 해석하는 것. 형변환 코드 생략가능, 멤버의 개수는 줄어들음.
//다운캐스팅 : 부모타입으로 추정되는 녀석을 자식타입으로 해석해보는 것. 형변환 코드 생략 불가능, 멤버의 개수는 늘어난다.
//다운캐스팅에서 부모타입으로 추정되는 녀석이 사실상 자식타입에 꼭 맞는 녀석이길 확신하고 쓰는 캐스팅. 
//진짜 숏다리 부모였으면 메모리영역을 침범해서 대참사가 날 수 있다.
 

#include "ambulance.h"
#include "fire_car.h"

int main(void)
{

	Car* car = new Car("검정색", 4);
	Fire_Car* fire_car1 = new Fire_Car("빨간색", 2, true);
	Fire_Car* fire_car2 = nullptr;
	Ambulance* ambulance = new Ambulance("���", 5, true);


	cout << "car의 주소 : " << car << endl;
	cout << "fire_car1의 주소 : " << fire_car1 << endl;
	cout << "fire_car2의 주소 : " << fire_car2 << endl;
	cout << endl << endl;

	//자기 자신의 클래스로 인스턴스를 생성해서 별 문제될게 없는 코드
	fire_car1->water();
	//업캐스팅	     //업캐스팅은 이제 익숙해진줄 알고 자신있었는데 이건 또 새로웠다.
	car = ambulance; //car나 ambulance 둘다 주소저장하는 포인터 변수들이다. 지금 주소의 교환이 이루어지는 중인 것이다.

	cout << endl << endl;
	cout << "car의 주소 : " << car << endl;
	cout << "fire_car1의 주소 : " << fire_car1 << endl;
	cout << "fire_car2의 주소 : " << fire_car2 << endl;

	//car는 숏다리 부모여서 자식의 기능인 water()에 안닿는다...
	//car.water();
	
	//car는 지금 27번 line에서 ambulance의 주소를 받아 업캐스팅된 상태인데 그것을 Fire_Car으로 해석하겠다니?
	//규격이 맞지않아 오류가 발생한다!
	//ambulance = (Fire_Car*)car;

	car = (Ambulance*)car; // 그렇다. Ambulance으로 해석해야 규격에 맞는 것이다.

	cout << endl << endl;
	//! 다형 클래스 형식 : 가상함수가 존재하는 클래스
	//dynamic_cast이라는 진보된 형변환은 반드시 가상함수가 있는 다형 클래스에서만 적용된다. 이 친구를 위해서 car클래스의 stop에 virtual 붙이고 왔다.
	fire_car2 = dynamic_cast<Fire_Car*>(car);
	fire_car2->water();

	//근본을 벗어나니 에러가 발생한다. 짧은 다리의 비애...
	//car->siren_alarm();
	ambulance->siren_alarm();

	delete car;
	delete fire_car1;
	delete fire_car2;
	delete ambulance;

	return 0;
}