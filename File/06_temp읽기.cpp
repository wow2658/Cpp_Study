#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#if 0
int main(void)
{
	/* temp.txt
	*  1 23.5
	   2 36.5
	*/
	ifstream is("C:\\Users\\tak26\\Desktop\\temp.txt", ios::in);

	if (!is)
	{
		cerr << "파일 열기 실패" << endl;
		exit(1);
	}

	int hour = 0;
	double temperature = 0.0;

	while (is >> hour >> temperature)
	{
		cout << hour << "시: 온도 " << temperature << endl;
	}



	return 0;
}
#endif

#if 1

#include <vector>
class TempData
{
public:
	int hour;
	double temperature;
};
int main(void)
{
	vector<TempData> temps;
	int hour = 0;
	double temperature = 0.0;
	double sumTemp = 0.0, avgTemp = 0.0;

	/* temp.txt
	*  1 23.5
	   2 36.5
	*/
	ifstream is("C:\\Users\\tak26\\Desktop\\temp.txt", ios::in);

	if (!is)
	{
		cerr << "파일 실패" << endl;
		exit(1);
	}



	while (is >> hour >> temperature)
	{
		temps.push_back(TempData{ hour,temperature });
		sumTemp += temperature;
	}
	cout << "벡터의 사이즈 : " << temps.size() << '\n';

	for (TempData t : temps)
	{
		cout << t.hour << "시: 온도 " << t.temperature << '\n';
	}

	avgTemp = sumTemp / temps.size();

	cout << "평균 온도값 : " << avgTemp << '\n';


	return 0;
}
#endif