#include <iostream>
#include <type_traits>

template<typename T>
T Divide(T a, T b)
{
	static_assert(std::is_floating_point<T>::value, "float값이 필요합니다."); //7번라인
	if (std::is_floating_point<T>::value == false)
	{
		std::cout << "float값이 필요합니다.\n";
		return 0;
	}
	return a / b;
}

int main(void)
{
	std::cout
		<< std::boolalpha
		<< "int인가요?" << std::is_floating_point<int>::value << std::endl;

	std::cout << Divide(5.1,7.3 ) << std::endl; 

	std::cout << Divide(5,2) << std::endl; //24번라인
	/*
	1>D:\Cpp_Study\Template\39_type_traits+static_assert.cpp(7,16): error C2338: static_assert failed: 'float값이 필요합니다.'
	1>D:\Cpp_Study\Template\39_type_traits+static_assert.cpp(24,15): message : 컴파일되는 함수 템플릿 인스턴스화 'T Divide<int>(T,T)'에 대한 참조를 확인하세요.
	*/
}