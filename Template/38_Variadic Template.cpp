// 이제는 그래도 template으로 생긴건 다 알아보겠지 싶었으나
// 신기하게 생긴 녀석이 더 있었다
// template<typename T, typename...Params>
// void Print(T&& a, Params&&... args) ...라니? 이것도 참 무섭게 생겼다.
// 가변길이템플릿이라고 불린다.

#include <iostream>
using namespace std;

void Print() // 맨 마지막 용도
{
	std::cout << std::endl;
}

//Template parameter pack
template<typename T, typename...Params>
//Function parameter pack
void Print(T&& a, Params&&... args)
{
	//std::cout << sizeof...(args) << std::endl;
	//std::cout << sizeof...(Params) << std::endl;
	std::cout << a;
	if (sizeof...(args) != 0)
	{
		std::cout << ", ";
	}
	//We can forward a function parameter pack
	Print(std::forward<Params>(args)...);
}

int main()
{
	// Print({ 1,2.5,3,4 });
	Print(1, 2.5, 3, "4");
	return 0;
}

/*
1. Print(1, 2.5, 3, "4") ;
2. Print(2.5, 3, "4") ;
3. Print(3, "4") ;
4. Print("4") ;
5. Print() ;
*/
