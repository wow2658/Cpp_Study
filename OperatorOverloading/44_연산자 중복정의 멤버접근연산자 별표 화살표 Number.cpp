#include "Number.h"
#include <memory>
int main(void) {


#if 1
	//int* ptr = nullptr;
	Number num(new int);	
	*num = 50;
	num.printNumber();

	*num = 30;
	num.printNumber();
	
	unique_ptr<int> p(new int);
	*p = 100;
	cout << *p << endl;
	//delete p;

#else

	Number num(5);	
	num->printNumber();

	*num = 30; //매개변수 생성자 호출
	(*num).printNumber();

#endif

	return 0;
}