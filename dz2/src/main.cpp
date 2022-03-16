#include <iostream>
#include "myVector.hpp"

int main()
{
	myVector *numbers = new myVector();
	
	for (int i = 1; i <= 10; i++)
	{
		numbers->push_back(i);
	}
	std::cout << std::endl;
	numbers->print();

	myVector *numbers_copy = new myVector();

	*numbers_copy = *numbers;
	
	while (!numbers_copy->empty())
	{
		std::cout << numbers_copy->pop_back() << " ";
		//numbers_copy->pop_back();
	}
	std::cout << std::endl;
	
	return 0;
}