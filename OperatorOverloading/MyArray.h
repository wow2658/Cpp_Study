#pragma once
#include <iostream>
using namespace std;

const int SIZE = 10;	//전역 상수 


class MyArray {
private:
	int arr[SIZE];
public:
	MyArray() 
	{	//초기화
		for (int i = 0; i < SIZE; i++) 
		{
			arr[i] = 0; 
		}
		cout << "기본 생성자 호출" << endl;
	}
	~MyArray() 
	{
		cout << "소멸자 호출" << endl;
	}


	//중복함수 정의 obj.operator[](int_index) 
	//원본에 영향을 줘야하니까 Ref
#if 1
	int& operator[](int i) 
	{
		//배열의 인덱스를 초과하면 에러 처리하는 기능 추가
		if (i >= SIZE || i < 0) 
		{
			cout << "잘못된 인덱스 접근입니다. ";
			return arr[i];
		}
		return this->arr[i];
	}
#endif
	//int getValue(int i) {
	//	return arr[i];
	//}
};
