//프로그램이 실행(Runtime 시) 도중에 동적으로 메모리를 할당 받는 것을
//동적 메모리 할당 (Dynamic Memory Allocation)이라고 한다.
//동적 메모리는 메모리 공간 중 힙(Heap)-사용자 정의 메모리 영역에 할당받는다.
//만약에 충분한 메모리가 존재한다면, 그 요청은 운영체제에서 승인되고 할당이 되는 절차가 존재한다.
//메모리가 충분치 않다면 bad_allocation 오류가 발생되는 것을 
//Exception 23-1에서 실습하면서 볼 수 있었다.

//new(동적 할당 연사자)를 통하여 동적 메모리 할당을 요청할 수 있다.

//근데 동적 메모리 할당을 왜 포인터 다루다가 배우는지?
//왜냐하면 힙은 포인터를 통해서만 접근할 수 있기 때문이다. 
#include <iostream>
#include <memory> // 스마트 포인터

using namespace std;

int main(void)
{
	//일반 배열(스택 할당)과 동적 배열을 비교
	int size = 0;
	int* ptr1 = nullptr;
	cout << "How many integers should I make an array to store?? : ";
	cin >> size;

	//int arr_s[size] = { 0 }; 
	//오류가 났다! 초기화 할 때 일반 배열의 크기에는 상수값이 들어가야한다. expression must have a constant value

	ptr1 = new int[size];
	//동적 배열에서는 오류가 나지 않았다.
	for (size_t i = 0; i < size; i++)
	{
		cout << "ptr1[" << i << "] 값 : " << (ptr1 + i) << endl;
	}
	for (size_t i = 0; i < size; i++)
	{
		//Garbage Value
		cout << "*ptr1[" << i << "] 값 : " << *(ptr1 + i) << endl;
	}
	cout << "초기화 후 " << endl;
	for (size_t i = 0; i < size; i++)
	{
		*(ptr1 + i) = i;
		cout << "*ptr1[" << i << "] 값 : " << *(ptr1 + i) << endl;
	}

	cout << "메모리 반납 전 ptr 포인터 값 : " << ptr1 << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << "*ptr1[" << i << "] 값 : " << *(ptr1 + i) << endl;
	}
	//delete[] ptr1;	//동적 메모리 반납
	//cout << "delete[] ptr1 후 ptr 포인터 값 : " << ptr1 << endl;
	//for (size_t i = 0; i < size; i++)
	//{
	//	cout << "*ptr1[" << i << "] 값 : " << *(ptr1 + i) << endl;
	//}
	delete ptr1;	//포인터도 사라짐
	cout << "delete ptr1 후 ptr 포인터 값 : " << ptr1 << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << "*ptr1[" << i << "] 값 : " << *(ptr1 + i) << endl;
	}

	// 원래는 delete ptr1만 하게 되면 첫번째 포인터가 가르킨 메모리만 해제해준다.
	// 하지만 여기에서는 delete[] ptr1와 delete ptr1이 똑같이 동작하였다.
	// 왜일까? 
	//----------------------------------------------------------------
	unique_ptr<int[]> ptr_u(new int[size]);
	for (size_t i = 0; i < size; i++)
	{
		//cout << "ptr_u[" << i << "] 값 : " << *(ptr_u + i) << endl; 스마트 포인터에서는 안된다.

		//Garbage Value
		cout << "ptr_u[" << i << "] 값 : " << ptr_u[i] << endl;
	}

	//C++에서는 new연산자를 통하여 동적할당을 해도 초기화가 이루어지지 않는다.
	//다른 언어에서는 0으로 초기화 해준다고 한다.

	return 0;
}
