// 언리얼이나 c++ 내부 라이브러리 코드를 들여다보면
// 신기하게 생긴 template을 많이 보게 된다.
// T(&arr)[size] 이게 뭔가 싶고
// template<typename T, int size> 이건 또 뭔가 싶었다.
// 그것들을 잘 이해하고 싶다.

#include <iostream>

//Non-type template parameter
template<int size>
void Print() 
{
	// size++; // 오류난다. 컴파일 시간에 계산된걸로 밀고 나가야해서 const취급이다.
	char buffer[size];
	std::cout << size << std::endl;
}

//Requires size as explicit argument
//template<typename T>
//T Sum(T* parr, int size) 
//{
//	T sum{};
//	for (int i = 0; i < size; ++i) 
//	{
//		sum += arr[i];
//	}
//	return sum;
//}

//Size is implicitly calculated in non-type template argument
template<typename T, int size>
T Sum(T(&arr)[size]) // 크기가 size이고 요소로 T를 같는 arr을 레퍼런스로 가져온 거구나! 하고 읽을 수 있어야함.
{
	T sum{};
	for (int i = 0; i < size; ++i) 
	{
		sum += arr[i];
	}
	return sum;
}
int main() 
{
	int i = 3; 
	// Print<i>();		 // 이건 오류난다.
	//			<컴파일 시간에 계산이 가능한 인자가 들어가야한다.>
	Print <sizeof(i)>(); // 이건 컴파일할때 크기가 상수로 정해져서 통과된다.
	Print<3>();			 // 보통은 이게 국룰이다.


	int arr[]{ 3,1,9,7 };
	//int (&ref)[5] = arr ; // arr사이즈인 4보다 큰게 들어가서 오류난다.

#if 0
	auto it = std::begin(arr);

	_EXPORT_STD template <class _Ty, size_t _Size>
		_NODISCARD constexpr _Ty* begin(_Ty(&_Array)[_Size]) noexcept {
		return _Array;
	}
	_EXPORT_STD : 표준 라이브러리의 기능을 사용하도록 지시.이 함수를 다른 파일에서 호출할 수 있도록 해줌
	_NODISCARD  : 함수의 반환 값을 사용하지 않을 경우 컴파일러가 경고를 표시.즉, 함수의 반환 값이 무시되지 않도록 함
	constexpr   : 컴파일 시간에 평가될 수 있음
	noexcept    : 이 함수가 예외를 던지지 않음
#endif
	int sum = Sum(arr);     // 두번째 인자로 size를 명시하지 않았는데 template이 알아서 4로 해석했다.

	std::cout << sum << std::endl;

	return 0;
}