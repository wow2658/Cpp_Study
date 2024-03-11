#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_greater_than_5(int value)
{
	return (value > 5);
}

int main(void)
{
	vector<int> numbers1{1,2,3,4,5,6,7,8,9,10};
	auto count1 = count_if(numbers1.begin(),numbers1.end(), is_greater_than_5);
	cout << "5보다 큰 정수들의 개수 (함수버전): " << count1 << endl;

	vector<int> numbers2{ 1,2,3,4,5,6,7,8,9,10 };
	auto count2 = count_if(numbers2.begin(), numbers2.end(), //[](int x){return (x>5);});
		[](int value)
		{
			return (value > 5);
		}
	);
	cout << "5보다 큰 정수들의 개수 (람다버전): " << count2 << endl;
	return 0;
}