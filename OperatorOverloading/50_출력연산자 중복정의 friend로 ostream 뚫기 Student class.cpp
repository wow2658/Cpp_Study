//ostream : 출력을 수행하는 클래스 (cout은 객체)
//istream : 입력을 수행하는 클래스 (cin은 객체)
//#include <iostream>으로 상당히 익숙하게 다뤄왔던 클래스이다.
//ostream, istream, iostream은 자식클래스인데 
//예전에 File(2024-03-06)다룰때 ios 상속 계층도를 직접 작성했던적이 있으니 참고하자. 

//ostream의 클래스 내부에는 이미 << 연산자가 아래와 같이 많이 오버로딩 되어있다.
//ostream& operator<<(bool& val);
//ostream& operator<<(short& val);
//ostream& operator<<(long& val);
//ostream& operator<<(int& val);
//....
//istream의 클래스 내부에는 이미 >> 연산자가 아래와 같이 많이 오버로딩 되어있다.
//istream& operator>>(bool& val);
//istream& operator>>(short& val);
//istream& operator>>(long& val);
//istream& operator>>(int& val);
//....
//이미 컴파일러 자체에서 상당히 많이 제공해주기 떄문에 변경,추가,삭제 등을 함부로 할 수 없다. 
//때문에 접근이 막혀있는데 이러한 isream ostream 관련된 입출력은 우리가 friend를 이용해 뚫을 수 있다. 
//friend 용도가 가독성뿐만이 아니라 이런 용도도 있구나 느낄수 있었다. 
//<< >> friend 함수로 중복정의를 하는 경우가 아래와 같다. 

#include "Student.h"

int main(void) {

	Student s1(20, "김민지"), s2(18, "강해린"), s3;
	
	//아래 코드는 iostream의 라이브러리 파일에 있는 연산자를 호출하는 것
	cout << 1 << endl;
	cout << "abc" << endl;

	//아래 코드는 Student 클래스에 있는 프렌드 함수를 호출하는 것
	//무엇을 보고 알았을까?
	//내가 의도한 양식대로 출력되는 것을 보면 알 수 있다. [나이 : 00, 이름 : ㅇㅇ] 편리하다.
	//반환값으로 ostream& 으로 줬던 이유가 아래처럼 연속콤보로 쓰기 위함인것은 연산자 중복정의를 할 때부터 여러번 다뤘다.
	cout << s1 << s2 << s3 << endl;

	return 0;
}




