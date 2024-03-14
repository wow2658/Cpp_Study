#include "Member.h"

int main(void)
{
	Member* pMem1 = new Member("pMem1", 21);	 pMem1->printInfo();
	Member* pMem2 = new Member("pMem2", 22); pMem2->printInfo();
	cout << pMem1->getName() <<"의 주소값 : " << pMem1 << endl;
	cout << pMem2->getName() <<"의 주소값 : " << pMem2 << endl;
	cout << "--------------------pMem1 = pMem2 연산 ----------------- " << endl;
	pMem1 = pMem2;
	pMem1->printInfo();
	pMem2->printInfo();
	cout << pMem1->getName() << "의 주소값 : " << pMem1 << endl;
	cout << pMem2->getName() << "의 주소값 : " << pMem2 << endl; //주소 결과값이 같다 heap에서 주소 공유해서

	Member Mem3("Mem3", 11); Mem3.printInfo();
	Member Mem4("Mem4", 7); Mem4.printInfo();
	cout << Mem3.getName() << "의 주소값 : " << &Mem3 << endl;
	cout << Mem4.getName() << "의 주소값 : " << &Mem4 << endl;
	cout << "--------------------Mem3 = Mem4 연산 ----------------- " << endl;
	Mem3 = Mem4;
	Mem3.printInfo();
	Mem4.printInfo();
	cout << Mem3.getName() << "의 주소값 : " << &Mem3 << endl;
	cout << Mem4.getName() << "의 주소값 : " << &Mem4 << endl; //주소 결과값이 다르다 stack에서 값만 복사해서

	cout << "\n지금까지는 복사생성자가 호출되지 않았다.\n"<< endl;
	
	Member cMem5 = *pMem1;
	Member cMem6(Mem3);
	cMem5.setName("cMem5");
	cMem6.setName("cMem6");

	cout << "\n복사생성자 호출 성공\n" << endl; // 복사생성자는 새롭게 만들때만 호출된다.
	cout << cMem5.getName() << "의 주소값 : " << &cMem5 << endl;
	cout << cMem6.getName() << "의 주소값 : " << &cMem6 << endl; //주소 결과값이 다르다

	//정의되지 않은 오퍼레이터 ==

	//if (*pMem1 == *pMem2) cout << "true" << endl;
	//else cout << "false" << endl;

	//if (Mem3 == Mem4) cout << "true" << endl;
	//else cout << "false" << endl;

	//if (cMem5 == *pMem1) cout << "true" << endl;
	//else cout << "false" << endl;

	//if (cMem6 == Mem3) cout << "true" << endl;
	//else cout << "false" << endl;

	if (pMem1 == pMem2) cout << "pMem1 == pMem2 true"<<endl;
	else cout << "false" << endl;

	if (&Mem3 == &Mem4) cout << "true" << endl;
	else cout << "&Mem3 == &Mem4 false" << endl;

	if (&cMem5 == pMem1) cout << "true" << endl;
	else cout << "&cMem5 == pMem1 false" << endl;

	if (&cMem6 == &Mem3) cout << "true" << endl;
	else cout << "&cMem6 == &Mem3 false" << endl;

	cout << "\n이제 소멸자를 호출해보자.\n" << endl;
	delete pMem1;
	//delete pMem2; // 오류 발생! shallow copy 문제때랑 똑같다.
					// 같은 동적 할당 주소를 공유하는데, pMem1이 지워버린걸 pMem2똑같이 지워버리려고 하니까 터졌다.

	Mem3.setName("Mem3");
	return 0;
} //아주 알찼다.