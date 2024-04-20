#include <iostream>

template<typename T>
struct Unnamed
{
	T operator()(T x, T y) const
	{
		return x + y;
	}
};
#pragma region Functor_function object.cpp
template<typename T, int size, typename Comparator>
void Sort1(T(&arr)[size], Comparator comp)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{	// 컴파일 시간에 계산도 가능하다.
			{
				if (comp(arr[j], arr[j + 1]))
				{
					T temp = std::move(arr[j]);
					arr[j] = std::move(arr[j + 1]);
					arr[j + 1] = std::move(temp);
				}

			}
		}
	}
}
struct Comp2
{
	bool operator()(int x, int y)
	{
		return x > y;
	}
};
#pragma endregion

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation)
{
	for (size_t i = 0; i < size; i++) //size가 알아서 친절하게 잘 맞는다.
	{
		operation(arr[i]);
	}
}

template<typename T>
struct __Unnamed
{
	int offset;
	__Unnamed(int off) : offset(off) {}
	void operator()(T& x)
	{
		x += offset;
		++offset;
	}
};

int main(void)
{
	auto fn = []()
		{
			std::cout << "Lambda" << std::endl;
		};
	fn();
	std::cout << typeid(fn).name() << std::endl;
	//class `int __cdecl main(void)'::`2'::<lambda_1>
	//람다는 클래스 취급이다.

	auto sum = [](auto x, auto y) noexcept(false)
		{
			return x + y;
		}; // 람다 끝나고 세미콜론 까먹지말자 -> 근데 이게
	// 람다 끝나서 붙인게 아니라 auto sum = @@; 때문이다.

	std::cout << "Sum is : " << sum(5.5f, 2.2f) << std::endl;
	Unnamed<int> n;
	std::cout << "n.operator()(5.5f,2.2f) is : (int)" << n(5.5f, 2.2f) << std::endl;


	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
	Comp2 comp;
	Sort1(arr, comp);
	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	Sort1(arr, [](auto x, auto y) {return x < y; });

	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
	///////////////////////////////////////////////////////////////
	int offset = 5;
	ForEach(arr, [offset](auto& x) mutable
		{
			x += offset;
			offset++; // 오류.. mutable이라면? 해결!
		});

	ForEach(arr, [](auto x)
		{
			std::cout << x << " ";
		});





	return 0;
}