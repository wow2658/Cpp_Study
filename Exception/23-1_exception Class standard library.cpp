// 표준 예외 : C++ 표준 라이브러리에서 제공하는 예외, 내가 예측하지 못하거나 건드리지 못하는 부분을 잡아내 적절한 예외경고를 발생시켜 준다. 덕분에 throw를 안써도 된다.
// 헤더파일 exception파일과 catch(exception& e){}으로 이용한다.
		// 배열 인덱스 넘는건 표준예외에 없다.


#include <iostream>
#include <string>
#include <exception>
using namespace std;

//int main(void)  // bad allocate	class std::bad_alloc
//{
//	try
//	{
//		int* p = new int[엄청큰수]; // 힙에다가 동적할당으로 몇바이트를 할당하는 걸까요?? -> 4*100000바이트 
//		delete p;
//	}
//	catch (const exception& e)
//	{
//		cout << "메모리 할당 에러" << e.what() << endl;
//	}
//
//	return 0;
//}

int main(void) // string too long	class std::length_error
{
	try
	{
		string str = "";
		str.resize(-1);

	}
	catch (const exception& e)
	{
		cout << typeid(e).name() << endl; 
		cerr << e.what() << endl; 
	}

	return 0;
}