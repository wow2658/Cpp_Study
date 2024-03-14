#include "Person.h"

void func1(Person person);
Person func2();

int main(void)
{
	//복사 생성자가 호출되는 시점 3가지


	//1번째: 같은 종류의 객체로 초기화 하는 경우
	//AActor copy(ori) or AActor copy = ori
	Person person_ori("진소한", 28);
	person_ori.printName();
	cout << endl;

	Person person_copy(person_ori);
	person_copy.printName();
	cout << endl;

	cout << "person_copy 인스턴스 값 변경 후" << endl;
	person_copy.setName("유진성");
	person_copy.setAge(30);
	person_copy.printName();

	//2번째: 객체를 함수에 전달하는 경우
	//void func1(obj)
	func1(person_ori);
	func1(person_copy);
	cout << "main()으로 돌아옴" << endl;
	cout << "--------------------------" << endl;
	//3번째: 함수가 객체를 반환하는 경우
	Person person_func2 = func2();
	cout << "main()으로 돌아옴" << endl;
	return 0;
}

void func1(Person person)
{
	cout << "func1() 실행" << endl;
	cout << person.getName() << ", " << person.getAge() << endl;
	cout << "func1() 종료" << endl;
}

Person func2()
{
	Person person_temp;
	person_temp.setName("temp");
	person_temp.setAge(18);
	Person person_temp2("temp2", 10);
	cout << person_temp.getName() << ", " << person_temp.getAge() << endl;
	cout << person_temp2.getName() << ", " << person_temp2.getAge() << endl;

	return person_temp;
}