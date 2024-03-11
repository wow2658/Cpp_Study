// 매크로 함수 #define 함수명(인자이름) (리턴할 값)
// 
// 전처리기가 처리해서 실행속도에 이점이 있다.
// 복잡해지면 구현이 어렵고 가독성이 낮아져 디버깅이 어려워진다.
#if 0
#define SQUARE(x) ((x)*(x))
#define PIE 3.14
#define CIRCLE(x) ((PIE)*(x))

#include <iostream>
using namespace std;

int main(void)
{
	// 이미 전처리기에서 처리가 끝나서 디버깅해보면 호출하는 함수가 스택에 쌓이지않고 안보이는것을 알 수 있다. 그래서 빠른 것이다.
	cout << SQUARE(3) << endl;
	cout << CIRCLE(3) << endl;

	return 0;
}
#endif
// 인라인(inline) 함수 : 매크로 함수의 어려운 정의 방법을 개선
// 일반 함수처럼 정의 가능
// 매크로 함수보다는 살짝 느리지만 역시 빠름
// 컴파일러에 의해서 처리가 된다.
// 자료형에 의존적 -> templapte을 사용해서 해결해야한다.

#include <iostream>
using namespace std;

inline int SQUARE(int x)
{
	return x*x;
}


template<typename T>
inline T SQ_temp(T x)
{
	return x*x;
}

int main(void)
{
	cout << SQUARE(5) <<endl;
	cout << SQUARE(5.5) <<endl; //error
	cout << SQ_temp(5) <<endl;
	cout << SQ_temp(5.5) <<endl;
	cout << SQ_temp(1.4f) <<endl;
	
	double result = 0.1*0.2;
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << SQUARE(result)<<endl;
	cout << SQ_temp(result)<<endl;
	cout << SQ_temp<double>(result)<<endl;

	return 0;
}