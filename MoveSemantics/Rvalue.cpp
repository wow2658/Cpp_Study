// Move Semantics는 C++11부터 도입되었는데 C++을 공부하면 꽤 초반에 등장하는 개념이다.
// 그러다보니 대충보고 넘어가거나 몇가지는 너무 당연하게 알고 있다고 스킵하는 경우가 종종 있었는데,
// 운영체제를 공부할 수록 대단히 중요하다고 느껴서 다시 돌아와서 제대로 깊게 공부해봐야겠다고 생각했다.

// 이것을 공부하는 단원에서는 꼭 l-value와 r-value, 그리고 copy constructor와 move constructor가 등장한다.
// 이것들이 Move Semantics와 어떤 관련이 있는지, 또 Move Semantics를 왜 사용하는지 알아보자.


// 맨처음부터 놀랄만한 것이 있었는데
// C++11 이전에는 value category가 lvalue rvalue로만 나눠졌던 것이
// xvalue prvalue glvalue가 추가되어 더 다양하게 나뉜다는 것을 생전 처음 알게되어 충격이었다.
// 심지어는 operator = 에서 왼쪽에 오면 left value, 오른쪽에 놓이면 right value라고 외웠던 개념도
// 이제는 const 한정자 때문에 정확하지 않다는 것도 알게되었다. 
// 일단 오늘부로 lvalue의 l이 left가 아니라 locator라는 것으로 깨우치고 가도록하자.


//1. Lvalue와 Rvalue 구별하기
// Lvalues are things you can grab an address for and use at a later time
// Rvalues are transient or temporary in nature, they only exist for a short time, and are quickly destroyed by the system when no longer needed
// Identity, Addess의 유무에 관심을 기울인다. 다음에도 가져다 쓸 수 있는지? 아니면 빨리 사라져버리는 휘발성인지?
// 변수명같은 건 lvalue다. 상수 그자체와 (상수,변수)끼리의 산술결과, 함수전신은 rvalue다. std::move()결과물도 rvalue다.
//  


//2. lvalue와 rvalue 조작 
// lvalue는 &연산자를 통해 주소를 따올 수 있다. rvalue는 휘발되는 녀석이라 주소를 취득해 올 수 있는 주소가 없으니 &연산자를 붙일 수 없다.
//	1) int x는 x=y x=2처럼 lvalue rvalue 다 잘받는다.
//  2) int& x는 x=y는 돼도 x=2는 안된다. 상수에서 어떻게 레퍼런스를 따와서 조작한단 말인가?
//  3) const int& x는 조작할 생각을 안하니까 상수와 동귀어진이 가능한 것이다. 
//  4) int&& x는 가장 무섭게 생겼지만 이렇게 이해하면 편했다. 
//	   이름도 주소도 없이 찰나에 휘발되어 버릴 rvalue를 꽉잡아서 이름을 주고 생명을 연장 시켜주는 느낌인 것이다.
//	   그렇기 때문에 이미 Identity와 address가 있는 lvalue는 받지않고 rvalue만 꽉잡는 녀석인 것이다.


//3. 4가지 func 종류에 들어갈 수 있는 함수인자 구별하기. 위에서 여러 예시와 나만의 언어로 이해한 것이 이제 아래 개념과 이어진다.
//  1) func(int x)			<--	lvalue rvalue
//	2) func(int& x)			<--	lvalue only
//	3) func(const int& x)	<--	lvalue rvalue
//	4) func(int&& x)		<-- rvalue only
// 왜 위와 같이 필터링 되는지 납득하기 위해 2.의 내용이 필요했던 것이다.
// 번외로 func(int* x)도 있긴한데 애초에 이건 주소값(&lvalue)만 넘길 수 있기 때문에 헷갈릴 일은 없어 빠졌다. 
// rvalue는 주소값이 프로그래머가 접근할 수없는 곳(ex_레지스터)있고 그마저도 바로 휘발된다는 것을 다시 상기하자.


//4. func(int&& x)인 4유형에 lvalue을 정말 꼭 넣고싶을때 방법이 없을까?
// 이때 등장하는 것이 std::move()다.
// std::move()는 lvalue를 rvalue로 캐스팅하는 역할을 한다.
// std::move()를 통해 func(int&& x)로 들어가는것에 성공한 lvalue는 unique_pointer때 처럼 껍데기만 남는다고 생각해야한다.
// 재사용하고 싶으면 미리 assign을 해놓든 해야한다. 그냥 껍데기를 재활용할 수는 없다.


//5. 4가지 func 종류에 무엇이 들어 갈 수 있는지는 이제 이해할 수 있다.
//	lvalue 들어가기 가능! rvalue 들어가기 가능!에만 멈춰있지말고 각 func가 하는 역할과 권한도 생각하고 넘어가자.
//	1) func(int x)			<-- 들어오는 lvalue, rvalue는 레지스터에 임시로 복사(비효율적) 핑퐁해서 x로 담아낼 것이다. 내 소유 x는 완성되었다.
//	2) func(int& x)			<-- 들어오는 lvalue에 대한 레퍼런스 x를 얻는다. 내가 x를 조작하면 밖에 있는 lvalue도 변화할 것이다.
//	3) func(const int& x)	<-- 들어오는 lvalue에 대한 레퍼런스 x를 얻지만, const라서 조작할 수는 없다. 
//	4) func(int&& x)		<-- 들어오는 rvalue를 복사하지 않고 직접 이동(내가 완성하고 싶어하는 x의 포인터를 들어온 녀석에게 겨낭해서 훔쳐오는 식)으로 
//								x를 완성시키고 소유할 것이다.
//

//6. copy constructor와 move constructor 그리고 copy assignment operator 와 move assignment operator
// 5.의 1)인 func(int x)에서 핑퐁이라고 비유한 것이 Copy였다. 이것을 해결하기 위해 Move semantics을 배우면서 rvalue reference를 이해하려고 노력한 것이다.
// 왜 Copy가 비효율적이라고 하는 것일까? 규모가 백만 넘어가는 객체를 다룰때를 상정하면 이해가 간다.
// 사용하지도 않을 temporary한 객체를 굳이 만들어서 복제하고 날려버린다는게 많은 부담이 될 것이다. 포인터 조작 몇번하며 Move라는 행동이면 가벼울텐데 말이다.
// 
//	
//	5의 법칙, 0의 법칙

//...작성중...

//7. xvalue prvalue gvalue이건 무엇인가?
// A prvalue is a "pure rvalue" or a literal
// An xvalue is an "expiring value" or temporary object. eXpiring에서 따온 x. 
// A glvalue is a "generalized lvalue" (either an lvalue or an xvalue)
// 위와 같이 단순 정의로는 와닿지 않는다. 
// 확실하게 구별할 수 있는 특성으로 나눠보자.

// identity를 가지는가? move 될 수 있는가?
// 
// lvalue  : identity를 가지지만 move 될 수 없다. ex) int a의 a.

// xvalue  : identity를 가지고	move 될 수 있다. ex) std::move()결과물, rvalue reference를 리턴하는 함수의 결과물

// prvalue : identity를 가지지 않고 move 될 수 있다. ex) 1 'a' 같은 literal

// rvalue  : move 될 수 있으면 다 rvalue다.			-> move될 수 있다는건 std::move()에게 몸을 맡겨야 rvalue처럼 move 될 수 있다는 뜻.

// glalue  : identity를 가지면 다 glvalue다.			-> identity를 가진다는 것. 그것은 휘발성이 아니며 주소로 찾아갈 수도 있고 이름도 있다는 것.

// 제대로 분류하다보니 이게 무슨일인가? xvalue는 그럼 rvalue도 되고 glvalue도 된다는것인가?
// 그렇다. 교집합에 해당된다. 알아보기 쉽게 그려보자.
//---------------------------------------------------
//		       glvalue	  	   	rvalue      
//			  /	   	 \		  /		   \		
//       lvalue		   xvalue	     prvalue
//---------------------------------------------------
//		  ((identity))			((move))





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

