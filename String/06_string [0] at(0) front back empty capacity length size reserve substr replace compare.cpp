#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	// 멤버함수는 클래스 안에 정의된 함수를 뜻한다.
	// 함수안에 있다는 뜻과 클래스 안에 있다는 뜻을 구별하자.
	// 의식하지 않았더니 괜히 새로운걸 배우는 느낌이었다.
	// 멤버 함수는 단독사용이 안되고 먼저 객체가 할당되어야 거길 통해 호출할 수 있다.

	string str = "hello";
	//s[i] = 실제 값
	cout << str[0] << endl;			//h
	cout << str.at(0) << endl;		//h
	cout << str.front() << endl;	//h
	cout << str.back() << endl;		//o


	cout << str.empty() << endl;	//0
	cout << str.capacity() << endl;	//15
	// length()와 size()의 차이
	// 언제나 같은 값을 리턴하지만 
	// length()는 단순히 문자열의 길이를 나타낸다. -> string 클래스에 종속적이다. 시간 복잡도는 O(N) 반환자료형  Immutable 특성을 갖는 객체(String, Array)에서 제공
	// size()는 해당 string객체가 메모리에서 실제 사용하고 있는 크기를 나타낸다. -> 컨테이너 다루는곳에서는 다 쓸수있다. 시간 복잡도는 O(1) Mutable 특성을 갖는 객체(Collections)에서 제공
	cout << str.length() << endl;	//5
	cout << str.size() << endl;		//5
	cout << str.max_size() << endl;	//9223372036854775807

	str.reserve(100); // 크기 재할당시 100만큼 더해주는 것이 아니다. 100에서 가장 가까운 정해진 크기만큼 할당해준다. 
	cout << str.capacity() << endl;	//100 -> 111
	str.clear();
	cout << str + "clear" << endl;

	string s1{"hello"};
	string s2{"aa"};
	string s3{"abc"};
	string s4{"ac"};
	string s5{"aa"};
	cout << "-----------------------------------------------------"<<endl;
	cout<<s1.substr(2,3)<<endl;			//llo
	cout<<s1.replace(2,3,"hi")<<endl;	//hehi
	cout<<s2.compare(s3)<<endl;			//-1	aa abc
	cout<<s2.compare(s5)<<endl;			//0		aa aa
	cout<<s4.compare(s2)<<endl;			//1		ac aa

	return 0;
}