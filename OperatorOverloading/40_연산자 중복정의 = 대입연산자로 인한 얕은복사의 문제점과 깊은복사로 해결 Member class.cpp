#include "Member.h"

int main(void) {

	Member member1(1, "강해린");
	Member member2(2, "김민지");

	cout << "대입 연산자 호출 전" << endl;
	cout << "&member1.name의 주소 : " << (int*)member1.name << endl;
	cout << "&member2.name의 주소 : " << (int*)member2.name << endl;

	member2 = member1; //여기에서 얕은복사가 이루어졌다면 아래에서 주소가 같게 나올것이고,
	cout << endl << endl;

	cout << "대입 연산자 호출 후" << endl;
	cout << "&member1.name의 주소 : " << (int*)member1.name << endl;
	cout << "&member2.name의 주소 : " << (int*)member2.name << endl;
	cout << "&member1.name의 주소 10진수 버전: " << *(unsigned long long*) & member1.name << endl;
	cout << "&member2.name의 주소 10진수 버전: " << *(unsigned long long*) & member2.name << endl;

	member1.printMember();
	member2.printMember();

	return 0; //여기에서 소멸자가 호출될때 대참사가 일어날 것이다. 
	//해결방법은?? 깊은 복사를 위해 프로그래머가 직접 대입연산자를 구현해놓는것!
	//복사생성자때와 비슷한 해결방법이다. 
	//MyArray_shallowcopy.h 와 Member.h를 잘 비교해보자.
}


#if 0

Member& operator=(const Member& member2)
{
	//1.원래 있던 동적 메모리를 소멸시킨다.
	delete[] this->name;
	this->num = member2.num;

	//2.새롭게 동적할당을 한다.
	this->name = new char[strlen(member2.name) + 1];

	//3.member2의 name값을 복사한다.
	strcpy_s(this->name, strlen(member2.name) + 1, member2.name);
	cout << this->name << "의 대입 연산자 호출" << endl;
	return *this;

	//? 왜 위와같이 귀찮게 새롭게 만들어서 대입하는걸까?
	//	-> name의 길이가 다르니까!
}

MyArray(const MyArray& other) : size(other.size), data(new int[other.size]), name(other.name) //this->data = other.data가 아니라 아예 새로 만들어서 새주소 전달
{
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = other.data[i];
	}
	cout << "복사 생성자 호출" << endl;

}

#endif