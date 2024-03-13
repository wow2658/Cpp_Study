//몇개의 정수를 저장합니까? : 5
//정수를 입력하시오 : 75
//정수를 입력하시오 : 15
//정수를 입력하시오 : 25
//정수를 입력하시오 : 35
//정수를 입력하시오 : 55
//입력된 정수는 : 75, 15, 25, 35, 55
//----------------------------------------------------------------------------------
#include <iostream>
#include <new>
using namespace std;

int main(void)
{

	int size = 0, i = 0;
	int* ptr = nullptr;

	cout << "몇개의 정수를 저장합니까? : ";
	cin >> size;

	ptr = new (nothrow) int[size];
	//동적 메모리 할당에 실패하면
	if (ptr == nullptr)
	{
		cout << "메모리 할당 오류" << endl;
		return -1;
	}
	else
	{
		for (i = 0; i < size; i++)
		{   
			
			cout << "정수를 입력하시오 : ";
			cin >> ptr[i];
		}

		cout << "입력된 정수는 : ";
		for (size = 0; size < i; size++) 
		{		//0 1 2 3 4
			if (size < i - 1)
			{	
				//0, 1, 2, 3,
				cout << ptr[size] << ", ";
			}	//4
			else
			{
				cout << ptr[size] << endl;
			}	//0, 1, 2, 3, 4
		}
		delete[] ptr;	
	}
	ptr = nullptr;		
	return 0;
}