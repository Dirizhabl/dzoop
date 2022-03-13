#include <iostream>
#include <random>

#include "Point.hpp"
#include "Triangle.hpp"

#define RAND_KOEF RAND_MAX*0.1

int main(void)
{
	Point *triangle_points = new Point[3];

	double a, b, c;
	srand(time(NULL));
	do
	{	
		//random number generation to simulate input of triangle points
		for (size_t i = 0; i < 3; ++i)
		{
			triangle_points[i].x = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/100));
			triangle_points[i].y = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/100));
		}
		
		a = triangle_points[2].distance_to_point(triangle_points[1]);
		b = triangle_points[0].distance_to_point(triangle_points[2]);
		c = triangle_points[1].distance_to_point(triangle_points[0]);

	}while ((((a + b) <= c) || ((a + c) <= b) || ((c + b) <= a))  /*ovaj uvijet je za jednakostranican trokut  || (a != b || a != c || b != c)*/);
	
	std::cout << a << " " << b << " " << c << std::endl;
	
	Triangle *triangle = new Triangle(triangle_points[0], triangle_points[1], triangle_points[2]);

	(*triangle).print();

	int type = (*triangle).triangle_type();
	std::cout << "Trokut opsega : " << (*triangle).triangleCircumference();

	switch (type)
	{
	case 1:
		std::cout << " je jednakokračan." << std::endl;
		break;
	case 2:
		std::cout << " je jednakostraničan." << std::endl;
		break;
	case 3:
		std::cout << " je raznostraničan." << std::endl;
		break;
	
	default:
		std::cout << " nije ništa od navedenog. LOL!" << std::endl;
		break;
	}

	Point p;
		p.x = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/100));
		p.y = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/100));
	bool ret = p.is_inside_triangle(*triangle);

	std::cout << "Točka ";
	p.print();
	if(ret)
		std::cout << " je ";
	else
		std::cout << " nije ";
	std::cout << "unutar trokuta."<< std::endl;

	delete triangle;
	delete[] triangle_points;

	return 0;
}