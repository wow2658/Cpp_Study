//스마트 포인터는 Dangling 포인터, 메모리 누수 등 원시포인터의 여러 문제점을 줄이기 위해
//C++ 11에서 도입되었다.
//동적메모리가 알아서 자동으로 해제된다. 따로 delete가 필요없다.  
#include <iostream>
#include <memory>
#include <Windows.h>
using namespace std;

int* do_moving();
unique_ptr<int[]> uni_moving();

int main(void)
{
	int* ptr = do_moving();
	cout << ptr << endl;
	for (size_t i = 0; i < 10; i++)
	{
		//Garbage Value이 나오는 이유 : do_moving(){}블럭 끝나서 unique_ptr들이 자동으로 delete 되었다.
		//다만 return 으로 parr2.get()이 아니라 parr2.release()으로 넘겨받으면 살아있다.
		cout << "ptr[" << i << "] : " << ptr[i] << endl;
	}
	//원시포인터라서 해제해줘야한다.
	delete[] ptr; //ptr.reset() 안된다.
	//for (size_t i = 0; i < 10; i++) //error 확인
	//{
	//	//Garbage Value이 나오는 이유 : do_moving(){}블럭 끝나서 unique_ptr들이 자동으로 delete 되었다.
	//	//다만 return 으로 parr2.get()이 아니라 parr2.release()으로 넘겨받으면 살아있다.
	//	cout << "ptr[" << i << "] : " << ptr[i] << endl;
	//}

	cout << "=====================================================" << endl;
	
	unique_ptr<int[]> uni_mvptr1 = uni_moving();
	cout << uni_mvptr1 << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << "uni_mvptr1[" << i << "] : " << uni_mvptr1[i] << endl;
	}
	uni_mvptr1[1] = 1;
	uni_mvptr1[2] = 2;
	cout << "=====================================================" << endl;
	Sleep(3000); //#include <Windows.h> 3초 후에 아래 for문 돌리면 메모리 자동 해제 후의 값이 나올 것이라 기대했지만 그렇진 않다.
	

	//uni_mvptr1.reset();
	for (size_t i = 0; i < 10; i++)
	{
		cout << "uni_mvptr1[" << i << "] : " << uni_mvptr1[i] << endl;
	}
	cout << "프로그램 종료" << endl;
	return 0;
} // 대신 break point 걸고 여기까지 내려온뒤 uni_mvptr1 체크하면 메모리 해제되는것 직접 확인할 수 있음.

int* do_moving()
{
	//make_unique : 좀 더 안전성있게 인스턴스를 생성해주는 메소드(C++ 14에서 추가)
	//0으로 초기화까지 해준다.
	unique_ptr<int[]> parr = make_unique<int[]>(10);
	for (size_t i = 0; i < 10; i++)
	{
		//parr[0] : 0
		cout << "parr[" << i << "] : " << parr[i] << endl;
	}
	//옛날방식
	unique_ptr<int[]> ptr_u(new int[10]);
	for (size_t i = 0; i < 10; i++)
	{
		//ptr_u[0] 값 : -842150451
		cout << "ptr_u[" << i << "] 값 : " << ptr_u[i] << endl;
	}
	//-------------------------------------------------------------------------

//////****소유권 이전****//////
	unique_ptr<int[]> parr2 = nullptr;
	//parr2 = parr1; 오류가 난다. shared_ptr이었으면 가능했을텐데, unique_ptr이라 안된다!
	cout << parr << endl;
	parr2 = move(parr);		//이제 parr은 은퇴한다.
	int* p = parr2.get();
	cout << "넘겨받았네 : " << p[0] << endl;
	cout << "은퇴했는데 : " << parr << endl;	//은퇴했는데 왜부르냐고 초록줄 경고도 뜬다. 0000000000000000

	/*parr2.reset();
	cout << "리셋 후 parr2 :  " << parr2 << endl;
	cout << "리셋 후 parr2[0] :  " << parr2[0] << endl;*/

	//cout << parr2 << endl; //error 확인
	//for (size_t i = 0; i < 10; i++)
	//{
	//	//Garbage Value이 나오는 이유 : do_moving(){}블럭 끝나서 unique_ptr들이 자동으로 delete 되었다.
	//	cout << "ptr[" << i << "] : " << parr2[i] << endl;
	//}

	//return parr2.get();	//-842150451
	return parr2.release(); //0
}

unique_ptr<int[]> uni_moving()
{
	unique_ptr<int[]> uni_mvptr2 = make_unique<int[]>(10);
	for (size_t i = 0; i < 10; i++)
	{
		cout << "uni_mvptr2[" << i << "] : " << uni_mvptr2[i] << endl;
	}

	unique_ptr<int[]> uni_mvptr3 = nullptr;

	uni_mvptr3 = move(uni_mvptr2);
	uni_mvptr3[1] = 96;
	uni_mvptr3[2] = 0123;	// 8진수 83


	return uni_mvptr3;		//uni_mvptr3.release()가 아니다.
}