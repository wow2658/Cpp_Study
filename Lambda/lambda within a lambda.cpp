#include <iostream>

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation)
{
	for (int i = 0; i < size - 1; ++i)
	{
		operation(arr[i]);
	}
}

class Product
{
	std::string name;
	float price;
public:
	Product(const std::string& n, float p) :name(n), price(p) {	}
	void AssignFinalPrice()
	{
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };

		//Capture this
		ForEach(taxes, [basePrice, this](float tax)
			{
				float taxedPrice = basePrice * tax / 100;
				price += taxedPrice;
			});
	}
	float GetPrice()const
	{
		return price;
	}
};


int main()
{
	atexit([]()
		{
			std::cout << "Program is exitting..." << std::endl;
		});

	Product p{ "Watch", 500 };
	p.AssignFinalPrice();
	std::cout << p.GetPrice() << std::endl;

	//Lambda within a lambda
	[](int x)
		{
			x *= 2;
			[](int x) 
				{
					std::cout << x << std::endl;
				}(x); // x 넣어서 람다 돌리겠다.
		}(5); // 5 넣어서 람다 돌리겠다.

	return 0;
}