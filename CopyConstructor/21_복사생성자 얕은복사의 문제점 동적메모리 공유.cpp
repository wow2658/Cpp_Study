#include "MyArray_shallowcopy.h"

void func1(MyArray arr_ori);
int main(void)
{
	MyArray arr_ori(10,"ori");
	arr_ori.getData()[0] = 100;
	cout << "arr_ori.getData()[0]의 값 : " << arr_ori.getData()[0] << endl;
	cout << "arr_ori.getData()[0]의 주소값 : " << &arr_ori.getData()[0] << endl;
	
	
	//{
	//	//MyArray arr_clone = arr_ori;
	//	MyArray arr_clone(arr_ori);
	//	cout << "arr_clone.getData()[0]의 값 : " << arr_clone.getData()[0] << endl;
	//	cout << "arr_clone.getData()[0]의 주소값 : " << &arr_clone.getData()[0] << endl;
	//} //<- 이순간부터 shallow copy의 문제가 터지는 것을 확인
	
	
	func1(arr_ori); //func1로 직접 _CrtlsVaildHeapPinter(block)문제를 일으켜보자

	return 0;
}
//해결방법은 프로그래머가 직접 deep copy를 하는 복사 생성자를 정의하는 것이다.
void func1(MyArray arr_ori)
{
	MyArray arr_clone(arr_ori);
	cout << "arr_clone.getData()[0]의 값 : " << arr_clone.getData()[0] << endl;
	cout << "arr_clone.getData()[0]의 주소값 : " << &arr_clone.getData()[0] << endl;

}
// 이 소스코드는 오류 나는게 정상이다.