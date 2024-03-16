#include <iostream>
#include <string>
using namespace std;

class Member
{
private:
	int age;
	char* name; // 긴장하면서 동적 할당할 때 길이+1도 놓치지않고 해줄 준비 -> strcpy_s와 delete[]까지 자동으로 연상하자. 
public:
	Member(const int age, const char* name) //const char*도 떠올리자. 형한정어로 성능 이득보자.
	{
		this->age = age;
		this->name = new char[strlen(name) + 1];			//멤버변수로 동적할당 국룰	
		strcpy_s(this->name, strlen(name) + 1, name);		//복사를 통해 초기화하는 콤보까지 익숙해지자.
		cout << this->name << endl;
		cout << strlen(this->name) << endl;
		cout << "Member 매개변수 생성자 호출" << endl;
	}
	virtual ~Member()
	{
		delete[] this->name;		//virtual에 모든걸 맡기는게 아니라 동적할당은 스마트포인터 아닌 이상 꼭 직접 소멸시켜줘야한다.
		cout << "Member 소멸자 호출" << endl;
	}
};

class Health_Member : public Member
{
private:
	char* healthClubName; //char* 쓰는 순간 바로~ 뉴[슽렌(변수명)+1] 콘챠* 슽캎_s(,,) 딜[] 
public:

	Health_Member(const int age, const char* name, const char* healthClubName) : Member(age, name)
	{
		this->healthClubName = new char[strlen(healthClubName) + 1];
		cout << strlen(healthClubName) << endl;			//매개변수 길이 utf-8에서는 한글이 3바이트
		strcpy_s(this->healthClubName, strlen(healthClubName) + 1, healthClubName);
		cout << this->healthClubName << endl;			//실제값 출력
		cout << sizeof(this->healthClubName) << endl;	//이건 포인터 변수라 8바이트 나온다.
		cout << "Health_Member 매개변수 호출" << endl;
	}
	virtual ~Health_Member()
	{
		delete[] this->healthClubName;
		cout << "Health_Member 소멸자 호출" << endl;
	}
};

int main(void)
{
	//업캐스팅
	Member* mptr = new Health_Member(25, "스폰지밥", "겁쟁이 클럽");
	delete mptr;   //뉴딜!

	return 0;
}


