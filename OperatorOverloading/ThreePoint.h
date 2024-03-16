#pragma once

#include <iostream>
using namespace std;

class Three_Point 
{
private:
	double x;
	double y;
	double z;
public:
	Three_Point(int x = 0.0, int y = 0.0, int z = 0.0) : x(x), y(y), z(z)
	{
		cout << "매개변수 생성자 호출" << endl;
	}
	
	friend istream& operator >>(istream& in, Three_Point& threePoint) 
	//? istream의 파라미터 Three_point에는 const 안 붙인 이유는?
	//>>으로 입력을 받은 후에 무슨 일이 일어나는지 생각해보자. 
	//threePoint의 멤버변수인x y z 값을 변경하고 있지 않은가?? 
	//그러니 const를 붙이지 않은것이다.

	//또한 istream은 ostream와 다르게 파라미터 Three_point에 꼭 &을 붙여줘야한다.
	//const 떼어가며 멤버변수 x y z 변경해놨더니 알고보니 복사본이면 허무하잖소!
	{
		in >> threePoint.x >> threePoint.y >> threePoint.z;
		return in;
	}

	friend ostream& operator <<(ostream& os, const Three_Point& threePoint) 
	{
		os << "(" << threePoint.x << ", " << threePoint.y << ", " << threePoint.z << ")";
		return os;
	}

	//입력 연산자 >>을 중복정의 한다면 <<도 같이 중복 정의하자. 대칭성을 고려한 국룰이라고 한다.
};