// 원을 나타내는 Circle 클래스에서 원의 중심을 정수(int), 또는 실수(float, double)로 표시하고 싶다.
// Circle클래스는 템플릿 클래스로 만들어서 area()함수를 구현하시오.
// 
// 면적 : 314
#include <iostream>
using namespace std;

template <typename T>
class Circle
{
private:
	T x;
	T y;
	T r;
public:
	Circle(T x, T y, T r) : x(x)
		                  , y(y)
		                  , r(r) {}

	T area()
	{
		return this->r * this->r * 3.14;
	}
};
int main(void)
{
	//int r = 0;
	double r = 0;
	cout << "원의 반지름을 입력하시오 : ";
	cin >> r;
	//Circle<int> cir(0, 0, r);
	Circle<double> cir(0, 0, r);
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << "면적 : " << cir.area();
	cout.unsetf(ios::fixed);
	return 0;
}