#include "MyArray.h"

int main(void) 
{
	int arr3[] = { 1,2,3,4,5 };
	int arr4[] = { 1,2,3 };
	arr3[1] = 100;
	//arr3[6] = 100; //기본형 타입은 컴파일러 선에서 체크를 해주지않아 미리 오류가 발생한다.

	//배열명은 포인터 상수에 해당하기 때문에 다른 배열명으로 대입하면 오류가 발생한다.
	//크기가 다르니 어떤 메모리를 침범할지 모르기 때문이다.
	//arr4 = arr3;

	//배열이 클래스의 멤버 변수이기 때문에 []인덱스 연산자를 중복정의 해줘야한다.
	MyArray arr1;
	MyArray arr2;

	for (int i = 0; i < SIZE; i++) 
	{
		cout << "arr1[" << i << "] = " << arr1[i] << endl;
	}
	cout << endl << endl;

	arr1[4] = 100;
	cout << "arr1[4] = " << arr1[4] << endl;
	cout << "arr1[-1] = " << arr1[-1] << endl;
	cout << "arr1[16] = " << arr1[16] << endl;

	//MyArray 클래스에서 동적배열을 사용한다면 반드시 깊은 복사를 하는 대입연산자가 필요하다.
	arr2 = arr1; //12줄 코드를 보면 원래 배열에서는 오류나는게 맞다. -> 중요해서 Dynamic Array로 방지버전을 구현해보겠다.

	for (int i = 0; i < SIZE; i++) 
	{
		cout << "arr2[" << i << "] = " << arr2[i] << endl;
	}
	cout << endl << endl;

	arr2[4] = -100;
	cout << "arr2[4] = " << arr2[4] << endl;
	cout << "arr2[-1] = " << arr2[-1] << endl;
	cout << "arr2[16] = " << arr2[16] << endl;

	for (int i = 0; i < SIZE; i++) 
	{
		cout << "arr2[" << i << "] = " << arr2[i] << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < SIZE; i++) 
	{
		cout << "arr1[" << i << "] = " << arr1[i] << endl;
	}

	//동적 배열로 할당한게 아니라 소멸자 두번 호출될때 딱히 문제는 일어나지 않았다.
	return 0;
}