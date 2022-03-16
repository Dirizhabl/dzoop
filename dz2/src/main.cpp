#include <iostream>
#include "mVector.hpp"

int main()
{
	mVector<int> *numbers = new mVector<int>();
	
	for (int i = 1; i <= 10; i++)
	{
		numbers->push_back(i);
	}
	std::cout << std::endl;
	numbers->print();

	mVector<int> *numbers_copy = new mVector<int>();

	*numbers_copy = *numbers;
	
	while (!numbers_copy->empty())
	{
		std::cout << numbers_copy->pop_back() << " ";
		//numbers_copy->pop_back();
	}
	std::cout << std::endl;
	
	return 0;
}