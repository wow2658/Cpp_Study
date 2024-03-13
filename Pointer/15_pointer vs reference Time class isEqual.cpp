#include "Time.h"

bool isEqual(Time& t1, Time& t2);
bool isEqual(Time* pt1, Time* pt2);

int main(void)
{
	int h = 0, m = 0, s = 0;
	cout << "시 : ";	cin >> h;
	cout << "분 : ";	cin >> m;
	cout << "초 : ";	cin >> s;

	Time time1;
	time1.printTime();
	Time time2(h, m, s);

	time1.setHour(time2.getHour());		//time1->setHour() time2->getHour()는 오류
	time1.setMinute(time2.getMinute()); //포인터가 아니라 진짜 생성자로
	time1.setSecond(time2.getSecond()); //구현해버린 객체 인스턴스들이다. 
										//객체의 멤버함수에 접근하듯 쓴것이다.
	time1.printTime();
	time2.printTime();

	if (isEqual(time1, time2))
	{
		cout << "시간이 일치합니다." << endl;
	}
	else
	{
		cout << "시간이 일치하지 않습니다." << endl;
	}

	if (isEqual(&time1, &time2))
	{
		cout << "시간이 일치합니다." << endl;
	}
	else
	{
		cout << "시간이 일치하지 않습니다." << endl;
	}
	return 0;
}
bool isEqual(Time& t1, Time& t2)
{
	if (t1.getHour() == t2.getHour()
		&& t1.getMinute() == t2.getMinute()
		&& t1.getSecond() == t2.getSecond())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isEqual(Time* pt1, Time* pt2)
{
	if (pt1->getHour() == pt2->getHour()
		&& pt1->getMinute() == pt2->getMinute()
		&& pt1->getSecond() == pt2->getSecond())
	{
		return true;
	}
	else
	{
		return false;
	}
}