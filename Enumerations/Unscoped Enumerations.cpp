#include <iostream>
#include <vector>
#include <string>

//enum {Red, Green, Blue};			//Implicit initialization
//enum {Red=2, Green=3, Blue=4};	//Explicit initialization
//enum {Red=5, Green, Blue};		//Explicit, Implicit initialization
enum Direction { North = 90, South = 270, East = 0, West = 180 };

// enum Street {Main, North, Elm};   // Error, can't use North again
// unscope의 단점이다. 구별이 안되니까 중복으로 이름 지을 수 없다. -> North


std::string direction_to_string(Direction direction)
{
	std::string result{ "" };
	switch (direction)
	{
	case North:
		result = "North";
		break;
	case South:
		result = "South";
		break;
	case East:
		result = "East";
		break;
	case West:
		result = "West";
		break;
	default:
		result = "Unknown direction";
	}
	return result;
}

void test1() {
	std::cout << "\n--- Test1 --------------------------\n" << std::endl;

	Direction direction{ North };
	std::cout << "\nDirection " << direction << std::endl;
	std::cout << direction_to_string(direction) << std::endl;

	direction = West;
	std::cout << "\nDirection " << direction << std::endl;
	std::cout << direction_to_string(direction) << std::endl;


	// direction = 1;  // Compiler Error

	direction = Direction(100);			// static_cast<Direction>(100);
	std::cout << "\nDirection " << direction << std::endl;
	std::cout << direction_to_string(direction) << std::endl;

	direction = static_cast<Direction>(270);
	std::cout << "\nDirection " << direction << std::endl;
	std::cout << direction_to_string(direction) << std::endl;

	direction = Direction::East;
	std::cout << "\nDirection " << direction << std::endl;
	std::cout << direction_to_string(direction) << std::endl;

	direction = static_cast<Direction>(North);
	std::cout << "\nDirection " << direction << std::endl;
	std::cout << direction_to_string(direction) << std::endl;
}

enum Grocery_Item { Milk, Bread, Apple, Orange };

std::ostream& operator<<(std::ostream& os, Grocery_Item grocery_item)
{
	switch (grocery_item) 
	{
	case Milk:
		os << "Milk";
		break;
	case Bread:
		os << "Bread";
		break;
	case Apple:
		os << "Apple";
		break;
	case Orange:
		os << "Orange";
		break;
	default:
		os << "Invalid item";
		break;
	}
	std::underlying_type_t<Grocery_Item> value = std::underlying_type_t<Grocery_Item>(grocery_item);
	os << "\t:\t" << value;
	return os;
}

bool is_valid_grocery_item(Grocery_Item grocery_item)
{
	switch (grocery_item)
	{
	case Milk:
	case Bread:
	case Apple:
	case Orange:
		return true;
	default:
		return false;
	}
}

void display_grocery_list(const std::vector<Grocery_Item>& grocery_list)
{
	std::cout << "Grocery List" << "\n==============================" << std::endl;
	int invalid_item_count{ 0 };
	int valid_item_count{ 0 };
	for (Grocery_Item grocery_item : grocery_list)
	{
		std::cout << grocery_item << std::endl;  // std::ostream& operator<<(std::ostream& os, Grocery_Item grocery_item)

		if (is_valid_grocery_item(grocery_item))
			valid_item_count++;
		else
			invalid_item_count++;
	}

	std::cout << "==============================" << std::endl;
	std::cout << "Valid items\t:\t" << valid_item_count << std::endl;
	std::cout << "Invalid items\t:\t" << invalid_item_count << std::endl;
	std::cout << "Total items\t:\t" << valid_item_count + invalid_item_count << std::endl;
}

void test2() 
{
	std::cout << "\n--- Test2 --------------------------\n" << std::endl;

	std::vector<Grocery_Item> shopping_list;

	shopping_list.push_back(Apple);						
	shopping_list.push_back(Apple);						
	shopping_list.push_back(Milk);						
	shopping_list.push_back(Orange);

	// Grocery_Item item = 100;                         // Compiler error

	int Helicopter{ 1000 };
	// shopping_list.push_back(Helicopter);				// Compiler error
	shopping_list.push_back(Grocery_Item(Helicopter));  // Invalid item
	shopping_list.push_back(Grocery_Item(0));           

	display_grocery_list(shopping_list);
}

enum State { Engine_Failure, Inclement_Weather, Nominal, Unknown };
enum Sequence { Abort, Hold, Launch };


std::istream& operator>>(std::istream& is, State& state)
{
	// 사실상 int user_input;   
	// 나중에 enum의 데이터타입이 자동으로 변했을때를 유연하게 대처할 수 있다.
	std::underlying_type_t<State> user_input;
	is >> user_input;

	switch (user_input)
	{
	case Engine_Failure:
	case Inclement_Weather:
	case Nominal:
	case Unknown:
		state = State(user_input);
		break;
	default:
		std::cout << "User input is not a valid launch state." << std::endl;
		state = Unknown;
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Sequence& sequence)
{
	switch (sequence) 
	{
	case Abort:
		os << "Abort";
		break;
	case Hold:
		os << "Hold";
		break;
	case Launch:
		os << "Launch";
		break;
	}

	return os;
}

void initiate(Sequence sequence)
{
	std::cout << "Initiate " << sequence << " sequence!" << std::endl;   // std::ostream& operator<<(std::ostream & os, const Sequence & sequence)
}

void test3() {
	std::cout << "\n--- Test3 --------------------------\n" << std::endl;

	State state;
	std::cout << "Launch state: Engine_Failure(0), Inclement_Weather(1), Nominal(3) -> ";
	std::cin >> state;              // std::istream& operator>>(std::istream& is, State& state)

	switch (state)					// 사실상 switch (괄호)안에 정수 하나를 넣기 위한 험난한 여정인 것이다.
	{
	case Engine_Failure:			// Abort if Engine Failure
	case Unknown:					// or Unknown!
		initiate(Abort);
		break;
	case Inclement_Weather:
		initiate(Hold);
		break;
	case Nominal:
		initiate(Launch);
		break;
	}
}

int main()
{
	//  test1();
	test2();
	// test3();

	std::cout << "\n";
	return 0;
}