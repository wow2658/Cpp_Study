#include "Time.h"

int main(void) {

	Time time1(10, 22, 35), time2(10, 22, 35);

	cout.setf(cout.boolalpha);
	cout << (time1 == time2) << endl;
//	cout << boolalpha << (time1 == time2) << endl;
	cout << (time1 != time2) << endl;

	return 0;
}