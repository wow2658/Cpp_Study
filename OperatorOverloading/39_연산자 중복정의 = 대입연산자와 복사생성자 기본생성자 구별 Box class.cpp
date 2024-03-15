//대입 연산자는 컴파일러가 기본적으로 제공하며 
//객체의 모든 멤버변수의 값들이 얕은 복사로 이루어진다.
//대입 연산자 중복함수(operator=)는 반드시 멤버함수로 작성해줘야한다.
//-> 위의 말뜻은 그냥 읽기만 했었을때는 static으로 하지말라는건가 
//	 어떤 경우에서 어떤 의도로 하는 말인지 몰랐으나 
//   Box.h에서 직접 구현해보니 정확히 이해할 수 있었다.
//대입연산자는 이미 만들어진 인스턴스끼리 주고받으면.
//복사생성자는 새로운 인스턴스가 만들어질때 주고받으면. 
//-> 둘이 정말 닮아서 헷갈릴 수 있다. 정확하게 구별해내자

#include "Box.h"

int main(void)
{
	Box box1;
	box1.setName("box1");
	Box box2("box2", 30.0, 40.0, 50.0);
	Box box3 = { "box3",0.0,0.0,0.0 };
	Box box4(box2);			 //복사생성자 1유형
	box4.setName("box4");

	cout << "box2 인스턴스를 복사하기 전" << endl;
	cout << "box1의 값 : ";
	box1.display();
	cout << "box2의 값 : ";
	box2.display();
	cout << "box3의 값 : ";
	box3.display();

	//box1.operator=( box3.operator=(box2) );
	box1 = box3 = box2;
	//Box box5 = box3 = box2; //복사생성자 1유형 + box3의 대입연산자
	cout << "box2 인스턴스를 복사하기 후" << endl;
	cout << "box1의 값 : ";
	box1.display();
	cout << "box2의 값 : ";
	box2.display();
	cout << "box3의 값 : ";
	box3.display();
	return 0;
}