#include <iostream>
using namespace std;

int main()
{
	// 정리 : https://kcoder.tistory.com/entry/C-cout-%EC%9D%98-%EB%AA%A8%EB%93%A0-%EA%B2%83-%EC%82%AC%EC%9A%A9%EB%B2%95-%EC%86%8C%EC%88%98%EC%A0%90-%EC%B6%9C%EB%A0%A5%EC%96%91%EC%8B%9D


	int num = 2024;
	int num1 = 2024;
	

	cout << "기본 출력" << endl;
	cout << "10진수 num = " << num << endl;
	cout << "8진수 num = " << oct << num << endl;
	cout << "16진수 num = " << hex << num << endl;
	//cout << dec; 
	cout << "16진수 num1 = " << num1 << endl;

	double dnum1 = 10.0;
	double dnum2 = 12.345;
	cout << "dnum1 = " << *(unsigned long long*) & dnum1 << endl;
	cout << "dnum1 = " << hex << *(unsigned long long*) & dnum1 << endl;
	cout << "dnum2 = " << *(unsigned long long*) & dnum2 << endl;
	cout << "dnum2 = " << hex << *(unsigned long long*) & dnum2 << endl;
	cout << "dnum2 = " << oct << *(unsigned long long*) & dnum2 << endl;
	cout << "8진수 num1 = " << num1 << endl;
	cout << dec;
	// 실험해보니 cout << dec같은 명령이 cout의 성질을 계속 좌우한다는 것을 알 수 있었다.
	//! 그리고 부동소수점 표기들에게는 hex oct가 먹히지 않고 정수표기를 하겠다고 *(unsigned long long*) &를 붙여서 써줘야만 표현이 가능한 것을 확인했다.
	// 그냥 (long long)으로 캐스팅하면 소수부분이 날아가는데 위의 방법은 비트로 접근해서 위험하지만 보존된다.

	cout.setf(ios::showpos); // 동시에는 안된다.
	cout << "10진수 num = " << num << endl;
	cout << "8진수 num = " << num << endl;
	cout << "16진수 num = " << num << endl;
	cout.unsetf(ios::showpos);
	cout << '\n';
	cout.setf(ios::showbase | ios::uppercase | ios::showpoint);
	cout << "8진수 num = " << oct << num << endl;
	cout << "16진수 num = " << hex << num << endl;
	cout << "dnum2 = " << dnum1 << endl;
	cout << "dnum2 = " << oct <<dnum2 << endl;
	cout.unsetf(ios::showbase); // 동시에는 안된다.


	return 0;
}