#include <iostream>
#include <vector>
#include <list>

const char* GetErrorMessage(int errorNo) 
{
	return "Empty";
}
								
//typedef const char *(*PFN)(int);   // 중간에 있는 PFN을 쳐다볼줄 알아야한다.
using PFN = const char* (*)(int);    // 훨씬 깔끔하다. https://github-production-user-asset-6210df.s3.amazonaws.com/34699039/323846243-86bc7cc7-62e7-41c8-9828-2b8f3225f033.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAVCODYLSA53PQK4ZA%2F20240419%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240419T055430Z&X-Amz-Expires=300&X-Amz-Signature=165f4fd53e4bde6afa8a041a67347d10d693bbc26ff2cd6d89205adb44d50667&X-Amz-SignedHeaders=host&actor_id=34699039&key_id=0&repo_id=768099022
								     // using이 typedef보다 좋은 점 첫번째 체감

void ShowError(PFN pfn) 
{

}

typedef std::vector<std::list<std::string>> newdef; // typedef로 재정의하면 띄어쓰기 안에서 어디까지가 변수구나 하고 내가 분별할 줄 알아야한다.
using newdef2 = std::vector<std::list<std::string>>; // =으로 구분지어 놔서 편하다.
													 // using이 typedef보다 좋은 점 두번째 체감


// string말고 다른것도 유동적으로 넣기 위해 템플릿화 하고싶으면??

//template<typename T>
//typedef std::vector < std::list<T> > Names; 이건 에러난다.

template<typename T>
using Names = std::vector<std::list<T>>;     // 됐다!
											 // using이 typedef보다 좋은 점 세번째 체감


int main() 
{
	newdef names1;
	newdef2 names2;
	Names<std::string> nnames;
	Names<int> nnames_int;

	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
