//상속관계에서의 private, protected, public을 잘 다뤄보자
//상속 접근지정자에서 public: 공기처럼 신경안써도 된다.
//상속 접근지정자에서 private: 외부에서 public이어도 아예 접근 못하게 한다. 상속 관계를 가지는 class끼리는 신경안써도 된다.
//상속 접근지정자에서 protected: 외부에서 public이어도 파생클래스가 아닌 이상 접근을 못하게 한다. 이게 가장 애매한것 같다.
//main이 무언가로부터 파생된다는 개념이 존재하는건가?? 이쪽에서는 사실상 private 취급을 하는게 맞는것 같고
//다른 class들에게 기회를 살짝 열어준다는 쪽으로 생각하는게 약간의 차이인듯 하다.
//다중 상속 받을때 활용할 수 있지 않을까?

#include "student_Member.h"

int main(void) {

	Member member(2000, "강해린", "경북 김천");
	Student_Member sm(1000, "김민지", "강원도 춘천", "뉴진스");

	//sm.num; //'Member::num' not accessible because 'Student_Member' uses 'private' to inherit from 'Member'	


	cout << "학생 ID : " << member.getMember_Id() << endl;

	cout << "학생 ID : " << sm.getMember_Id() << ", ";
	cout << "학생 이름 : " << sm.getName() << ", 학생 주소 : " << sm.getAddress() << ", 학교 이름 : "
		<< sm.getSchoolName() << endl;

	return 0;
}