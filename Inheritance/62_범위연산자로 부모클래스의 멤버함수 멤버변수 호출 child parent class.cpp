#include "child_class.h"

int main(void) {

	Parent_Class pc(25);
	Child_Class cc(1000); //여기에서 부모의 기본 생성자 호출한다.
		
	pc.print();
	cc.c_print(); //여기에서 부모버전의 print()도 실행시킨다.

	return 0;
}