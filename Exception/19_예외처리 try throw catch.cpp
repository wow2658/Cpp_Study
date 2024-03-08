// 에러(err) : 의도치 않게 프로그램이 비정상 종료가 되는 것
//				하드웨어의 잘못된 동작, 고장으로 인한 오류, 정전, 배드섹터, 블루스크린, 0으로 나누기, 배열 범위 실수 등이 있다.
// 예외(exception) : 사용자의 잘못된 조작 or 프로그래밍으로 오류가 발생해 프로그램이 종료가 되는 것.
// 예외처리를 추가해주면 정상 실행 상태로 되돌릴 수가있다.
// 즉, 예외 처리의 목적은 프로그램을 정상 실행 상태로 돌리는 것이다!
// 일반 예외(컴파일 예외, checked exception) : 빨간줄, 잘못된 문법으로 컴파일 당시에 예외가 발생하는 것
// 실행 예외(런타임 예외, unchecked exception) : 예외 처리 코드를 생략해도 컴파일은 되는 예외 (경험 및 노하우에 따라 예외 처리 코드 필요)

#include <iostream>
using namespace std;

int main(void)
{
	int pizze_slice = 0;
	int persons = 0;
	int slices_persons = 0;

	try
	{
		cout << "피자 조각 수를 입력하시오 : ";
		cin >> pizze_slice;
		if (0 >= pizze_slice)
		{
			throw persons;
		}
		cout << "사람 수를 입력하시오 : ";
		cin >> persons;
		if (0 >= persons)
		{
			throw persons;
		}
	}
	//catch (...) 모든 경우에서 받고 싶을때
	catch (int e) // 타입이 꼭 일치해야한다. persons를 throw하니까 int로 받을 준비.
	{
		cout << "예외 발생" << endl;
	}


	slices_persons = pizze_slice / persons;
	cout << "한 사람당 피자는 : " << slices_persons << "조각입니다." << endl;

	return 0;

}
