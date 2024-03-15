#pragma once

#include <iostream>
using namespace std;

class Camera
{
private:

	//생성자를 private 영역에 둔다. 아주 특징적인 부분이다.
	//여기에 두면 외부에서 접근을 하지 못해서 인스턴스 생성을 막는 효과가 생긴다.
	Camera() {}

	//getInstance()에서 활약할 정적 멤버 변수의 포인터 형태를 선언한다.
	static Camera* instance;
public:
	static Camera* getInstance();

	void capture()
	{
		cout << "capture 완료" << endl;
	}
	~Camera()
	{
		delete instance;
		cout << "소멸자 호출" << endl;
	}
};

Camera* Camera::instance = nullptr;  //static 변수 포인터 초기화

Camera* Camera::getInstance() {
	if (!instance) {				//맨 처음이라면
		instance = new Camera();	//한 개의 인스턴스를 생성함.
		cout << "첫 번째 객체가 생성됨" << endl;
		return instance;			//이제 nullptr이 아님
	}
	else 
	{								//왜 또 만들려고 하는가? 
		cout << "인스턴스가 이미 만들어져 있음" << endl;
		return instance;			//이미 있는거 쓰시게
	}
}

