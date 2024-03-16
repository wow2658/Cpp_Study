#include <iostream>
using namespace std;

class Parent 
{
public :
	Parent() 
	{
		cout << "Parent 생성자 호출" << endl;
	}
	
	//~Parent()  
	virtual ~Parent() //여기는 virtual 필수
	{		
		cout << "Parent 소멸자 호출" << endl;
	}
};

class Child : public Parent 
{
public :
	Child() 
	{
		cout << "Child 생성자 호출" << endl;
	}
	//virtual ~Child() 
	~Child() //여기는 virtual 선택
	{
		cout << "Child 소멸자 호출" << endl;
	}
};

int main(void) 
{
	//업캐스팅 했을때 Parent로 해석하기로 해서, parent는 일단 그냥 본인이 parent인줄로만 안다.
	//그래서 예전에도 학습했듯이 부모 인스턴스는 자식의 멤버함수와 멤버변수에 접근을 못했었던건데
	//소멸할때도 마찬가지이다. child는 관심없고 사라질때 parent 소멸자만 호출하고 쏙 빠져버린다.
	//그럼 child가 차지하던 공간이 찌꺼기가 되어남아 메모리 누수 현상이 발생한다.
	//이를 해결하려면 virtual을 붙여줘서 본인이 v-table을 통해 사실 본인이 child급이었음을 일깨워주면 된다는 것을 알 수 있다.
	//언리얼 엔진에서는 이것을 자동으로 처리해줬을 것이다. 
	Parent* parent = new Child();
	cout << "parent 주소 : " << parent << endl;
	
	delete parent;
	
	return 0;
}

