#pragma once
#include <iostream>
using namespace std;

class Dynamic_Array 
{
private:
	int arrlen;
	int* arr;
	//! 이 부분이 핵심이다.
	Dynamic_Array& operator=(const Dynamic_Array& arr) {}
public:
	Dynamic_Array(int arrlen) 
	{
		this->arrlen = arrlen;
		this->arr = new int[arrlen];
		cout << "매개변수 생성자 호출" << endl;
	}
	~Dynamic_Array() 
	{
		cout << "소멸자 호출" << endl;
		delete[] arr;
	}
	//[] 중복함수 정의
	int& operator[](int index) 
	{
		if (index < 0 || index >= arrlen) {
			cout << "인덱스 범위 오류" << endl;
			exit(1);	//난죽택
		}

		return arr[index];
	}
};

