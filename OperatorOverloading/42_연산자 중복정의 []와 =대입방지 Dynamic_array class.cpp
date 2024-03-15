#include "Dynamic_array.h"

int main(void) {
	
	int a[] = { 1,2,3 };
	int* b = nullptr;
	//int b[] = { 1,2,3 }; -> 오류
	//배열명은	포인터 상수이기에 대입을 허가하지 않는다. 그러나,
	//int* b처럼	포인터 변수로 제공하면 대입이 가능하다. 
	b = a;



	Dynamic_Array arr1(5); //매개변수 생성자 호출
	Dynamic_Array arr2(4); //복사생성자 1유형이 아니다.

	//클래스 안에 정적배열, 동적배열 모두 []기호를 쓰려면 중복 함수정의를 해야한다.
	for (int i = 0; i < 5; i++) {
		arr1[i] = i + 1;	
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		arr2[i] = i + 1;	
	}
	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << endl;
	}
	for (int i = 0; i < 4; i++) {
		cout << arr2[i] << endl;
	}
	//이번 목표는 아래의 코드를 성립이 안되게 하는것이다.
	//? 왜 방지하려고 하는가?
	//	배열은 저장소의 일종이고 저장된 데이터는 유일성이 보장되어야 한다.
	//	저장소의 복사는 불필요하며 잘못된 일로 간주되어야 옳다.
	//arr1 = arr2;
	//? 그래서 어떻게 방지하는가?
	//	싱글톤에서 생성자를 private영역에 구현하여 방지했던것처럼
	//	대입연산자 Dynamic_Array& operator=(const Dynamic_Array& arr) {}를
	//	private에 구현해삔다.
	cout << endl << endl;

	//arr1은 0 1 2 3 4 까지였다. 5부르면 범위를 벗어나는 것이다.
	cout << arr1[5] << endl;
	return 0;
}