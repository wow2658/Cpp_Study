#include <iostream>
#include <stdio.h>
using namespace std;
void f(int i);
void f(int* i);
int main(void)
{
	//아래와 같이 포인터를 초기화하지 않으면 대참사가 일어날 수 있다.
	//int* ptr;
	//*ptr = 100;		
	//cout << ptr << endl;
	//위험해~~뭘 건드릴줄 알고!

	int number = 150;
	int* ptr = &number;
	cout << "ptr이 가지고 있는 주소값(number의 주소값) : " << ptr << endl;
	printf("C스타일로 출력해보자 : %p\n", ptr); //#include <stdio.h> 필요
	printf("메모리는 16진수로 나타내는것이 국룰이다 : %#010x\n", (unsigned int)ptr);
	cout << "포인터크기는 8바이트가 국룰이다. int*도 double* 어차피 주소를 담는건 똑같다.\n포인터 크기 : " << sizeof(ptr) << endl;

	//역참고, 간접참조 매번 나오는 키워드들. 간단하지만 생소하게 들릴수도 있으니 익숙해지자.
	*ptr = 200;
	cout << "ptr이 가리키고 있는 메모리에 저장되어 있는 실제 값 : " << *ptr << endl;


	double d_value = 1.77;
	int* ptr2 = nullptr;
	ptr = (int*)&d_value;
	double* ptr3 = &d_value;
	cout << "NULL의 값 : " << NULL << endl;			
	cout << "nullptr로 초기화한 ptr2의 값 : " << ptr2 << endl;
	cout << "강제로 먹인 ptr값  : " << ptr << endl;
	cout << "정상적인 더블 ptr3값  : " << ptr3 << endl;

	f(NULL);		//int 0 취급해버린다.
	f(nullptr);		//int* 대우 받는다.

	return 0;
}
void f(int i) {
	cout << "f(int) 함수 호출" << endl;
	return;
}
void f(int* i) {
	cout << "f(int*) 함수 호출" << endl;
	return;
}
