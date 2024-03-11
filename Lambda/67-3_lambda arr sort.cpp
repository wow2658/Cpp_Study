#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

bool compare(int x, int y)
{
	return x > y;
}

int main(void)
{
	array<int, 10> arr1 = { 50,40,30,20,10,100,320,2,4,7 };
	array<int, 10> arr2 = { 50,40,30,20,10,100,320,2,4,7 };
	array<int, 10> arr3 = { 50,40,30,20,10,100,320,2,4,7 };

	//arr1 정렬 sort함수 
	sort(arr1.begin(), arr1.end());
	cout << "[sort]함수 사용" << endl;
	for (int val : arr1)
	{
		cout << val << " ";
	}
	cout << endl << endl;

	//arr2 정렬 sort함수와 일반함수 이용 -> 내림차순 적용
	sort(arr2.begin(), arr2.end(), compare);
	cout << "[sort(arr, arr+10, compare)] 사용" << endl;
	for (int val : arr2)
	{
		cout << val << " ";
	}
	cout << endl << endl;


	//arr3 정렬 sort함수와 람다식 이용 -> 내림차순 적용
	sort(arr3.begin(), arr3.end(), [](int x, int y) {return x > y; });
	cout << "[sort(arr, arr+10, [](int x, int y) {return x > y; })] 사용" << endl;
	for (int val : arr3)
	{
		cout << val << " ";
	}
	cout << endl << endl;

	return 0;
}