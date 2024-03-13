#include <iostream>
#include <memory>
using namespace std;

class A
{
private:


public:
	int size;
	A(int size) : size(size)
	{

	}
	~A()
	{
		cout << "A 소멸자 호출됨" << endl;
	}
};

int main(void)
{
	shared_ptr<A> ptr_A = make_shared<A>(10);
	cout << "ptr_A의 주소 : " << ptr_A << endl;
	cout << "ptr_A의 참조 횟수 : " << ptr_A.use_count() << endl;

	shared_ptr<A> ptr_B = ptr_A;
	cout << "ptr_B의 주소 : " << ptr_B << endl;
	cout << "ptr_A의 참조 횟수 : " << ptr_A.use_count() << endl;
	cout << "ptr_B의 참조 횟수 : " << ptr_B.use_count() << endl;

	shared_ptr<A> ptr_C = ptr_A;
	cout << "ptr_C의 주소 : " << ptr_C << endl;
	cout << "ptr_A의 참조 횟수 : " << ptr_A.use_count() << endl;
	cout << "ptr_B의 참조 횟수 : " << ptr_B.use_count() << endl;
	cout << "ptr_C의 참조 횟수 : " << ptr_C.use_count() << endl;

	cout << "============================================ " << endl;

	ptr_C = nullptr;
	cout << "ptr_C 해제"<< endl;
	cout << "ptr_A의 참조 횟수 : " << ptr_A.use_count() << endl;
	cout << "ptr_B의 참조 횟수 : " << ptr_B.use_count() << endl;
	cout << "ptr_C의 참조 횟수 : " << ptr_C.use_count() << endl;
	cout << "ptr_C의 주소 : " << ptr_C << endl;
	

	ptr_B = nullptr;
	cout << "ptr_B 해제"<< endl;
	cout << "ptr_A의 참조 횟수 : " << ptr_A.use_count() << endl;
	cout << "ptr_B의 참조 횟수 : " << ptr_B.use_count() << endl;
	cout << "ptr_C의 참조 횟수 : " << ptr_C.use_count() << endl;
	cout << "ptr_B의 주소 : " << ptr_B << endl;
	
	cout << "ptr_A 해제 전" << endl;
	ptr_A = nullptr;					//소멸자 호출
	cout << "ptr_A 해제 후" << endl;

	return 0;
} //ptr_A = nullptr; 주석처리하면 여기에서 소멸자 호출
