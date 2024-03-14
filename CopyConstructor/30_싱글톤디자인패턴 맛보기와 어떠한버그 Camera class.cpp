//싱글톤(Singleton 디자인 패턴)
//싱글톤의 개념: 한 클래스에서 오직 하나의 인스턴스만 생성하여 사용하는 디자인
//하나의 인스턴스만 만들고자 생성자를 private 영역에 구현한다.
//getInstance()를 통해서 외부에서 접근할 수 있도록 만든다.
//싱글톤의 장점: 메모리 낭비를 줄이고 인스턴스 재사용으로 개발속도를 빠르게 한다.
//대표적인 예: DB커넥션풀, 공용프린터, 스레드풀, 스마트폰의 카메라
//또한, 필연적으로 '멀티스레드에서 어떻게 활용해왔나' 라는 질문이 따라오게 되므로
//시간이 된다면 관련 경험을 꼭 쌓도록 하자.

#include "camera.h"
#include <windows.h>
int main(void) {
	//하나의 클래스 Camera에서 하나의 인스턴스를 사용하자고 했다.
	//생성자를 private영역에 넣어서 아래의 코드가 오류나는것을 확인할 수 있다.
	//Camera carmera;					//의도가 잘 먹혔다.
	//Camera* camera1 = new Camera();   //동적 할당도 안되는 것이다.

	Camera* camera1 = Camera::getInstance();
	cout << "camera1 instance의 주소 : " << camera1 << endl;
	Camera* camera2 = Camera::getInstance();
	cout << "camera2 instance의 주소 : " << camera2 << endl;
	Camera* camera3 = Camera::getInstance();
	cout << "camera3 instance의 주소 : " << camera3 << endl;

	camera1->capture();
	camera2->capture();
	camera3->capture();

	//camera1->~Camera();
	delete camera1;
	Sleep(3000);
	//camera1 = nullptr;
	//system("pause");
	cout << "camera1 instance의 주소 : " << camera1 << endl;

	//? 아래의 캡쳐동작 코드는 원래 실행이 안되어야하는데 왜 되는걸까?? 
	//? 얘도 디버그 모드라서 그런건가? -> 릴리즈에서 실행해도 오류가 발생안한다..
	camera1->capture();

	//이미 delete camera1에서 소멸시켰는데 또 소멸시키려고하니 오류가 발생
	//예전에 복사생성자에서 얕은복사에서 봤던 현상처럼 
	//같은 주소(힙에 있는)를 포인팅해서 그렇다.
	//delete camera2;
	//delete camera3;
}
