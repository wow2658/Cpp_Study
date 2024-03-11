#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Box
{
private:
	T data;
public:
	Box() //: data(0) -> 이거 때문에 string에서 오류남
	{

	}
	~Box(); // 외부에서 구현하는 경우 -> 밑에 template <typename T> Box<T>::~Box() {구현}
	void setData(T data)
	{
		this->data = data;
	}
	T getData(); // 자동완성으로 밑에 구현해달라고 하면 편하다. 반환 자료형 void T 실수 주의!

};

int main(void)
{
	Box<int> box1; // 그냥 Box box;로 쓰면 오류나는 이유는?? -> 클래스 템플릿은 자료형을 제시하여 구체화하지 않으면 없는 코드로 취급한다.
	box1.setData(100);
	cout << box1.getData() << endl;
	cout << '\n';

	cout.setf(ios::fixed);
	cout.precision(16);
	Box<double> box2;
	box2.setData(96.0123456789);
	cout << box2.getData() << endl;
	cout.unsetf(ios::fixed);
	cout << '\n';

	Box<char> box3;
	box3.setData('A');
	cout << box3.getData() << endl;
	cout << (int)box3.getData() << endl;
	cout << '\n';

	Box<string> box4;
	box4.setData("안녕하세요");
	cout << box4.getData() << endl;

	return 0;
}

template<typename T>
Box<T>::~Box()
{
	
}

template<typename T>
T Box<T>::getData()
{
	return this->data;
}
