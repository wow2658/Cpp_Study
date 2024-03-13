#include "Dog.h" 
//#include <Dog.h> //이러면 인식 못한다.
#include <memory>
int main(void)
{
#if 0
	Dog* pdog = new Dog;

	cout << endl << "main()에서 pdog의 주소 : " << pdog << endl;
	cout << "pdog->name : " << pdog->getName() << endl;
	cout << "pdog->age : " << pdog->getAge() << endl;
	delete pdog; //이것만 해서는 pdog가 여전히 할당받았던 주소를 가지고있는다. //*pdog로 넘어가서의 공간을 해제해버렸을뿐이다.
	//pdog = nullptr; //이렇게 해야 비로소 pdog가 아무곳도 가르키지 않는다.
	cout << endl << "delete 후 main()에서 pdog의 주소 : " << pdog << endl;
	cout << "delete 후 pdog->name : " << pdog->getName() << endl;
	cout << "delete 후 pdog->age : " << pdog->getAge() << endl;
#else
	unique_ptr<Dog> udog = make_unique<Dog>();

	cout << endl << "main()에서 udog의 주소 : " << udog << endl;
	cout << "pdog->name : " << udog->getName() << endl;
	cout << "pdog->age : " << udog->getAge() << endl;

	//udog.reset(); //역시 스마트포인터는 알아서 nullptr로 처리해준다. 이래서 쓰는것 같다.
	cout << endl << "main()에서 udog의 주소 : " << udog << endl;
	cout << "pdog->name : " << udog->getName() << endl;
	cout << "pdog->age : " << udog->getAge() << endl;
#endif
	return 0; 
}//udog.reset() 안해도 여기에서 메모리가 정리된다!