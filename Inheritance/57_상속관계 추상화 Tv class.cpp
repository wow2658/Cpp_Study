#include "colorTv.h"
#include "smartTv.h"
#include "wideTv.h"

int main(void) {

	Tv tv(10);
	tv.channelUp();
	tv.channelDown();

	cout << endl << endl;

	ColorTv colorTv(10, "Blue");
	colorTv.printColorTv();
	colorTv.channelUp();
	cout << endl << endl;

	SmartTv smartTv(10, false);
	smartTv.smartOn(true);
	smartTv.smartOff(false);
	smartTv.channelUp();
	smartTv.printSmartTv();

	cout << endl << endl;

	WideTv wideTv(10, 32);
	wideTv.printWidtTv();
	wideTv.channelUp();
	
	return 0;
}