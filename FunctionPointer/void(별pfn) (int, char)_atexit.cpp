#include <iostream>

void Print(int count, char ch)
{
	using namespace std; // 이걸 구역마다 하는 스타일도 있구나
	for (int i = 0; i < count; ++i)
	{
		cout << ch;
	}
	cout << endl;
}
void EndMessage()
{
	using namespace std;
	cout << "End of program" << endl;
}
int main()
{
	//Register a handler. This handler will be invoked after main returns. 그래서 end of main -> End of program
	atexit(EndMessage);

	Print(5, '#');

	  void(*pfn) (int, char) = Print;			// pfn은 반환이 없고 인자로 int char를 받는 함수의 주소를 저장할 수 있는 함수포인터변수
	//void(*pfn) (int, char) = &Print;		// 어차피 함수의 이름도 주소를 명시하는것이라, 같은 의미이다.


	//One way to invoke function pointer
	(*pfn)(8, '@');							// pfn이 가지고있는 주소로 넘어가서 콱 찍는데 인자로 int char를 넘겨주는 느낌

	//Another way to invoke function pointer
	pfn(5, '+');							// 이런 방법도 있구나


	using namespace std; // 이걸 중간에 넣는 스타일도 있구나
	cout << "end of main" << endl;

	return 0;
}