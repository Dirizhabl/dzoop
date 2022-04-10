#include <iostream>
#include "list_extended.hpp"
#include "list.hpp"

void zad1();
void zad2();
void zad3();
int main()
{
	//zad1();
	zad2();
	//zad3();
	return 0;
}

void zad1()
{
	std::list<double> double_list{59.9, 13.7, 10.0, 98.44, 16.7, 20.269, 1.5};
	std::cout << "Sum: " << sum(double_list) << "\nProd: " << prod(double_list) << "\nMin: "<< min(double_list) <<"\nMax: "<< max(double_list) <<std::endl;
}

void zad2()
{
	list *lista = new list{};
	int temp;
	size_t count;
	std::cin >> count;
	for (size_t i = 0; i < count; i++)
	{
		std::cin >> temp;
		lista->push_front(temp);
	}
	lista->display();
	lista->reverse();
	lista->display();

	delete lista;
}

void zad3()
{
	list *lista = new list{};
	int temp;
	size_t count;
	std::cin >> count;
	for (size_t i = 0; i < count; i++)
	{
		std::cin >> temp;
		lista->push_front(temp);
	}
	std::cout << "average: " << lista->avg() << std::endl;
	std::cout << "min: " << lista->min()->n << std::endl;
	std::cout << "max: " << lista->max()->n << std::endl;
	std::cout << "Below average deleted: "<< std::endl;
	lista->delete_below_avg();
	lista->display();

	delete lista;
}