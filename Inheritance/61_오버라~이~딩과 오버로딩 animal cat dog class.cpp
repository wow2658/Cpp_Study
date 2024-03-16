//오버라이딩과 오버로딩
//오버라 "이" 딩(overriding) : 뭔가 길쭉한 느낌, 세로의 느낌, 상속의 느낌, 이미 있는거에 올라타는 ride 느낌
//	부모클래스로부터 상속받은 멤머함수를 자식클래스의 사용 용도에 따라서 (modify, change, 재정의)하는 것을 의미한다.
//	오버라이딩하려면 부모클래스 멤버함수의 선언부와 반드시 동일하게 해야한다.
//오버로딩(overloading) : 뭔가 가로로 넓쩍한 느낌, 확장되는 느낌, 매개변수 친구 새롭게 load하는 느낌
//	이것은 상속의 개념이 아니고 그냥 새로운 메소드를 만드는 것이다. 생성자 다룰때 많이 사용해왔다.
//	return타입은 오버로딩에 관여하지 않고 메서드명은 반드시 동일하게 해야하니 매개변수의 개수or타입or순서를 다르게 하자.

#include "dog.h"
#include "cat.h"

int main(void) 
{

	Animal animal;
	animal.speak();
	cout << &animal.age << endl;
	cout << endl << endl;

	Dog dog;
	dog.speak();
	cout << &dog.age << endl;
	cout << endl << endl;

	Cat cat;
	cat.speak();
	cout << &cat.age << endl;
	cout << endl << endl;

	return 0;
}