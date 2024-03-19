// Move Semantics는 C++11부터 도입되었는데 C++을 공부하면 꽤 초반에 등장하는 개념이다.
// 그러다보니 대충보고 넘어가거나 몇가지는 너무 당연하게 알고 있다고 스킵하는 경우가 종종 있었는데,
// 운영체제를 공부할 수록 대단히 중요하다고 느껴서 다시 돌아와서 제대로 깊게 공부해봐야겠다고 생각했다.

// 이것을 공부하는 단원에서는 꼭 l-value와 r=value, 그리고 copy constructor와 move constructor가 등장한다.
// 이것들이 Move Semantics와 어떤 관련이 있는지, 또 Move Semantics를 왜 사용하는지 알아보자.


// 맨처음부터 놀랄만한 것이 있었는데
// C++11 이전에는 value category가 lvalue rvalue로만 나눠졌던 것이
// xvalue prvalue gvalue가 추가되어 더 다양하게 나뉜다는 것을 생전 처음 알게되어 충격이었다.
// 심지어는 operator = 에서 왼쪽에 오면 left value, 오른쪽에 놓이면 right value라고 외웠던 개념도
// 이제는 const 한정자 때문에 정확하지 않다는 것도 알게되었다. 
// 일단 오늘부로 lvalue의 l이 left가 아니라 locator라는 것으로 깨우치고 가도록하자.


//1. Lvalue와 Rvalue 구별하기

// 작성중










#include <iostream>

//Returns r-value
int Add(int x, int y)
{
	return x + y;
}

//Return l-value
int& Transform(int& x)
{
	x *= x;
	return x;
}

void Print(int& x) 
{
	std::cout << "Print(int&)" << std::endl;
}

void Print(const int& x)
{
	std::cout << "Print(const int&)" << std::endl;

}

void Print(int&& x) 
{
	std::cout << "Print(int &&)" << std::endl;
}

int main()
{
	//x is lvalue
	int x = 10;

	//ref is l-value reference
	int& ref = x;
	//Transform returns an l-value
	int& ref2 = Transform(x);
	//Binds to function that accepts l-value reference
	Print(x);


	//rv is r-value reference
	int&& rv = 8;

	//Add returns a temporary (r-value)
	int&& rv2 = Add(3, 5);
	//Binds to function that accepts a temporary, i.e. r-value reference
	Print(3);
	return 0;
}

