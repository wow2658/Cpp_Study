#include "Monster.h" 
#include <memory>
using namespace std;
int main(void)
{
	unique_ptr<Monster> ChoiBao = make_unique<Monster>("초이바오", 100.0, 5073.0);
	ChoiBao->printMonsterInfo();

	shared_ptr<Monster> YSL = make_shared<Monster>("이머시브캐시트", 100.0, 6739.0);
	YSL->printMonsterInfo();
	cout << "참조 횟수 : " << YSL.use_count() << endl;

	auto acdoc(YSL);			//생성자를 통한 생성. 이런 방식으로는 처음해봤다.
	cout << "acdoc.use_count() : " << acdoc.use_count() << endl;
	cout << "YSL.use_count() : " << YSL.use_count() << endl;
	cout << "결국 use_count는 heap에 생성된 어느 \"이머시브캐스트\"가 참조된 strong Ref 숫자이다." << endl;
	cout << "YSL이 최초로 포인팅했을 뿐이다." << endl;


	cout << "acdoc->printMonsterInfo() : " << endl;
	acdoc->printMonsterInfo();
	
	cout << "acdoc주소 : " << *(unsigned long long*) & acdoc << endl;
	cout << "YSL주소 : " << oct<<*(unsigned long long*) & YSL << endl;
	cout << "0xF : " << hex<<0xF << endl;
	cout << "15 : " << 15 << endl;
	cout << dec << endl;
	cout << "15 : " << 15 << endl;

	YSL.reset();
	ChoiBao.reset();	//소멸자 호출
	acdoc.reset();		//소멸자 호출

	return 0;
}	//! 소멸자는 두번 호출된다.
	//Monster 객체는 두개만 생성되었기 때문이다.
	//포인터가 소멸할때는 소멸자를 호출하지 않는다. 이것을 착각하지말자.
	//그리고 악독은 새로운 Monster 객체를 생성한 것이 아니라
	//그저 YSL을 이용하고자 포인터로서 업힌것 뿐이다.

    //? 근데 왜 이머시브캐스트의 소멸자가 먼저 호출되는 건가?
    // 초이바오 주소 0x000001d4754cc0f0 ->2012012658928 더 높은숫자
	// 이머시브 주소 0x000001d4754c9e50 ->2012012650064 더 낮은숫자
    // 진짜 heap라서 높은주소부터 할당하고 내려오는건가??
    // 해제하는건 낮은 주소부터 싹 정리하면서 올라오는거고??