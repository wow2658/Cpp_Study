// - 함수포인터와 함수객체의 차이는 무엇일까?
// 함수 포인터는 인라인 될 수 없지만, 함수 객체는 인라인 될 수 있고 컴파일러가 쉽게 최적화 할 수 있다.
// 그래서 STL은 function object를 사용한다. 그리고 Functor가 function object의 줄임말이었다.

// - 인라인 때문이야? 그럼 인라인함수의 장점이 무엇인데?
// 인라인은 그냥 main에 쓴거처럼 인식되어 함수를 call하는 작업이 생략되고
// 이것이 성능 향상에 도움이 된다. 물론 그렇다고 전부 인라인 함수로 선언해버리면
// 프로그램의 크기가 커지고 메모리에 올라갔다 내려왔다 하는 일이 자주 생겨 수행속도가 떨어질 수 있다.
// 구현을 엄청 많이 해놓은 큰 함수보다는 간단한 작은 함수들을 inline으로 쓰자.
// 함수호출 비용을 아끼는것 말고도 complie 타임에 결정되어 오버헤드를 줄이고 속도를 향상시키는 효과도 있다.

//////
// 인라인함수는 1. 함수호출비용아낌 2.컴파일시점계산 으로 이득이구나
// 함수객체가 이게 되고, 함수포인터는 안되고~
//////

// - 함수호출비용을 좀더 정확하게
// 함수호출비용이란 함수를 호출하기 위하여 컴파일러가 자동으로 생성하는 코드의 일부
// 함수 호출전이 prefix고 함수 호출 후 종료 다음을 suffix라고 하는데
// Prefix에서 CPU의 레지스터 상태, 플래그 등을 스택에 저장하는 코드를 실행하는 작업을 하는데
// 이거해주느라 시간이 좀더 걸린다는거다.
// 
// - 근데 아까 오버헤드라는건 뭐였지?
// 프로그램이 실행되는 중에 다른 위치의 코드를 실행시켜야 할 때, 
// 간접적으로 시간, 메모리, 자원 등이 사용되는 현상이다.
// 아 그래서 아까 메모리에 올라갔다 내려왔다 그런 표현을 사용한거구나
//
// 이 밖에도 인라인남용하면 캐시적중률이 낮아져서 안좋아지네, 
// 페이징 적중 횟수가 증가하네 같은 용어들이 더 있는데, 이것은 나중에...



#include <iostream>

# pragma region function pointer
using Comparator0 = bool(*)(int, int);					 // 이제는 요 (*)개미똥꾸멍 같은 녀석과 non-type tamplate arg이 낯설면 안된다.

template<typename T, int size>
void Sort0(T(&arr)[size], Comparator0 comp)              // 시그니처는 고정이고 그중에 어떤 녀석이 들어올지 컴파일시간에는 모른다.
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (comp(arr[j], arr[j + 1]))				 // 들어온 comp종류따라 운명이 판가름되는 길
			{
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}


//Function pointers as comparators
bool Comp0(int x, int y)
{
	return x > y;					// 크면 true. 바꿔서 저리가시고 작으면 냅둬서
	// 오름차순
}
bool Comp1(int x, int y)
{
	return x < y;					// 작으면 true. 바꿔서 저리가시고 크면 냅둬서
}								    // 내림차순


#pragma endregion

# pragma region function object
template<typename T, int size, typename Comparator>
void Sort1(T(&arr)[size], Comparator comp)          // 어떤 시그니처든 받을 수있고
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (comp(arr[j], arr[j + 1]))			// 컴파일 시간에 계산도 가능하다.
			{
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}

//Function Object as comparator
struct Comp2
{
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

#pragma endregion

// 이렇게 효율성, 범용성 챙기다가 이제 람다로 넘어가는 것이다.


int main()
{
	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	Sort0(arr, Comp0);

	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	Sort0(arr, Comp1);

	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;


	Comp2 comp;
	comp(3, 5);   //comp.operator()(3,5);
	Sort1(arr, comp);

	for (auto x : arr)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;


	return 0;
}