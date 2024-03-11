// 배열의 길이를 사용자로부터 입력을 받고 입력받은 길이만큼 배열을 동적할당을 하여 반복문을 통해서
// 사용자로부터 입력을 받는다.
// 입력 받은 배열 요소들을 이용하여 가장 적은 값을 반환하는 T getSmallest(배열, 사이즈) 함수 템플릿을 작성하고 출력결과를 아래와 같이 나오도록 프로그래밍 해보자
// 
// 몇 개의 요소를 입력하시겠습니까? : 5
// list[0] : 12.3 
// ...
// list[4] : 9.6
// 입력이 완료되었습니다.
// 최소값 : 9.6
#include <iostream>
using namespace std;

template <typename T>
T getSmallest(T arr[], int size);

int main(void)
{
	int length = 0;
	cout << "몇 개의 요소를 입력하시겠습니까? : ";
	cin >> length;

	//double* list = new double[length];
	int* list = new int[length];

	for (int i = 0; i < length; ++i)
	{
		cout << "list[" << i << "] : ";
		cin >> list[i];
	}
	cout << "입력이 완료되었습니다.\n";
	//for (int i = 0; i < length; i++)
	//{
	//	cout << list[i] << " ";
	//}
	cout << "최소값은 " << getSmallest(list, length) << "입니다.\n";





	delete[] list;

	return 0;
}

template<typename T>
T getSmallest(T arr[], int size)
{
	T min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (min > arr[i]) min = arr[i];
	}
	return min;
}
