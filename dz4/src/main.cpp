#include <iostream>
#include "DynamicQueue.hpp"
#include "CDLL.hpp"
void zad1()
{
	DynamicQueue *queue = new DynamicQueue{};
	queue->print();

	double vals[] = {59.9, 13.7, 10.0, 98.44, 16.7, 20.269, 1.5};

	for (size_t i = 0; i < 7; i++)
	{
		queue->enqueue(vals[i]);
	}

	queue->print();

	delete queue;
}
void zad2()
{
	CDLL *dqueue = new CDLL(); 

	dqueue->print();

	double vals[] = {59.9, 13.7, 10.0, 98.44, 16.7, 20.269, 1.5};

	size_t count=0;
	for (auto& val:vals)
	{
		dqueue->prepend(val);
		count++;
	}
	std::cout << count << std::endl;
	dqueue->print();

	CDLL *dqueue_copy = new CDLL{*dqueue};

	dqueue_copy->print();

	delete dqueue;
	delete dqueue_copy;

}
int main()
{
	zad1();
	zad2();
	return 0;	
}