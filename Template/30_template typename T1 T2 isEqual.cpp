#include <iostream>
#include <string>
using namespace std;

template <typename T>
bool isEqual(T arr1[], T arr2[], int n)
{
	cout << "isEqual(T) 함수 템플릿 호출됨" << endl;
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] != arr2[i])
		{
			cout << "arr1[" << i << "] : " << arr1[i] << "이며, arr2[" << i << "] : " << arr2[i] << endl;
			return false;
		}
		cout << "arr1[" << i << "] : " << arr1[i] << "이며, arr2[" << i << "] : " << arr2[i] << endl;
	}
	return true;
}

template <typename T1, typename T2>
bool isEqual(T1 arr1[], T2 arr2[], int n)
{
	cout << "isEqual(T1, T2) 함수 템플릿 호출됨" << endl;
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] != arr2[i])
		{
			cout << "arr1[" << i << "] : " << arr1[i] << "이며, arr2[" << i << "] : " << arr2[i] << endl;
			return false;
		}
		cout << "arr1[" << i << "] : " << arr1[i] << "이며, arr2[" << i << "] : " << arr2[i] << endl;
	}
	return true;
}


int main(void)
{
	double list1[] = { 1.5, 1.9, 2.1,2.6,5.5 };
	double list2[] = { 1.5, 1.9, 2.1,2.6,5.5 };
	int list3[] = { 65, 66,67,68,69 };
	char list4[] = { 'A','B' ,'C' ,'D' ,'E' };

	string list5[] = { "A", "B" ,"C" ,"D" ,"E" };
	string list6[] = { "ABCDE" };
	string list7[] = { "A", "B" ,"C" ,"D" ,"E" };

	bool equal1 = isEqual<double>(list1, list2, 5);
	if (equal1)
	{
		cout << "두 개의 배열의 값이 같습니다." << endl;
	}
	else
	{
		cout << "두 개의 배열의 값이 다릅니다." << endl;
	}

	bool equal2 = isEqual<double, int>(list1, list3, 5);
	if (equal2)
	{
		cout << "두 개의 배열의 값이 같습니다." << endl;
	}
	else
	{
		cout << "두 개의 배열의 값이 다릅니다." << endl;
	}

	bool equal3 = isEqual<int, char>(list3, list4, 5);
	if (equal3)
	{
		cout << "두 개의 배열의 값이 같습니다." << endl;
	}
	else
	{
		cout << "두 개의 배열의 값이 다릅니다." << endl;
	}


	bool equal4 = isEqual<string>(list5, list6, 5);
	if (equal4)
	{
		cout << "두 개의 배열의 값이 같습니다." << endl;
	}
	else
	{
		cout << "두 개의 배열의 값이 다릅니다." << endl;
	}

	bool equal5 = isEqual<string>(list5, list7, 5);
	if (equal5)
	{
		cout << "두 개의 배열의 값이 같습니다." << endl;
	}
	else
	{
		cout << "두 개의 배열의 값이 다릅니다." << endl;
	}

	return 0;
}