#include "student.h"

int main(void) {

	Date date(2004, 1, 26);		//Date클래스 인스턴스 생성
	Student person("설윤", date);
	person.printStudent();

	return 0;
}