#include "Dog_member_unique_pointer.h" 
#include <memory>
int main(void)
{
#if 0
	Dog* pdog = new Dog;

	cout << endl << "main()에서 udog의 주소 : " << pdog << endl;
	cout << "pdog->weight : " << pdog->getWeight() << endl;
	cout << "pdog->age : " << pdog->getAge() << endl;
	delete pdog; 
	pdog = nullptr;
	cout << endl << "delete 후 main()에서 udog의 주소 : " << pdog << endl;
	cout << "delete 후 pdog->weight : " << pdog->getWeight() << endl;
	cout << "delete 후 pdog->age : " << pdog->getAge() << endl;
#else
	unique_ptr<Dog> udog = make_unique<Dog>();

	cout << endl << "main()에서 udog의 주소 : " << udog << endl;
	cout << "pdog->weight : " << udog->getWeight() << endl;
	cout << "pdog->age : " << udog->getAge() << endl;

	cout << endl << "main()에서 udog의 주소 : " << udog << endl;
	cout << "pdog->weight : " << udog->getWeight() << endl;
	cout << "pdog->age : " << udog->getAge() << endl;
	//udog.reset();
	cout << endl << "main()에서 udog의 주소 : " << udog << endl;
#endif
	return 0;
}// 진짜로 여기에서 udog와 heap에 int 10,1이 차지한 공간 날아갔다.