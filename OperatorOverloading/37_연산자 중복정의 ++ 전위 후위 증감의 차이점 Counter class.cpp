#include "Counter.h"

int main(void) {
	//기본형 타입은 연산자 중복정의에 해당하지 않는다. 사용자 정의 클래서에서만 적용된다는 것을 알고있자.
	int i = 0;
	cout << ++i << endl;

	Counter count;
	cout << "Counter 클래스의 value 초기값 : " << count.getValue() << endl;
	//++count;
	cout << "(++count).getValue() : " << (++count).getValue() << endl;
	cout << "(count++).getValue() : " << (count++).getValue() << endl; //낚였습니까?
	cout << "count.getValue() : " << count.getValue() << endl;
	
	return 0;
}
