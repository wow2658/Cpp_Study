#include "MyArray_deepcopy.h"

void func1(MyArray arr_ori);
int main(void)
{
	MyArray arr_ori(2, "ori2");
	arr_ori.getData()[0] = 500;
	arr_ori.getData()[1] = 1000;
	cout << "arr_ori.getData()[0]의 값 : " << arr_ori.getData()[0] << endl;
	cout << "arr_ori.getData()[0]의 주소값 : " << &arr_ori.getData()[0] << endl;
	//{
	//	//MyArray arr_clone = arr_ori;
	//	MyArray arr_clone(arr_ori);
	//	cout << "arr_clone.getData()[0]의 값 : " << arr_clone.getData()[0] << endl;
	//	cout << "arr_clone.getData()[0]의 주소값 : " << &arr_clone.getData()[0] << endl;
	//} 
	func1(arr_ori);
	arr_ori.name = "ori";
	return 0;
}
//해결방법은 프로그래머가 직접 deep copy를 하는 복사 생성자를 정의하는 것이다.
void func1(MyArray arr_ori) //복사생성자 호출 2번의 경우 ->이게 아직 익숙하지 않다.
{
#if 1
	MyArray arr_func1 = arr_ori;
	arr_func1.name = "func1";
	MyArray arr_func1(arr_ori);
	cout << "arr_func1.getData()[0]의 값 : " << arr_func1.getData()[0] << endl;
	cout << "arr_func1.getData()[0]의 주소값 : " << &arr_func1.getData()[0] << endl;
#else
	cout << "복사생성자 호출 2번의 경우 확인" << endl;
#endif

} //복사생성자 호출2번도 여기에서 사라진다.
