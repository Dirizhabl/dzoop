#include "PositionVector.hpp"
#include "Student.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "/home/vlatko/Desktop/pregrammin/faks/oop/dz2/include/myVector.hpp"

void zad1();
void zad2();
void zad3();

int main()
{
	//zad1();
	//zad2();
	//zad3();
	return 0;
}

void zad1()
{
	PositionVector p_vec[5];

	p_vec[0].x = 2.5;
	p_vec[0].y = 3.6;

	p_vec[1].x = 5.5;
	p_vec[1].y = 3.6;

	p_vec[2].x = 4.4;
	p_vec[2].y = 4.4;

	p_vec[3].x = 10.0;
	p_vec[3].y = 0.1;
	
	std::sort(p_vec, p_vec+5);
	std::reverse(p_vec, p_vec+5);

	for (auto &&v : p_vec)
	{
		v.print();
	}
}

void zad2()
{
	std::ifstream file;
	file.open("/home/vlatko/Desktop/pregrammin/faks/oop/dz3/data.txt", std::ifstream::binary | std::ifstream::in);
	if(!file.is_open())
		std::cout << "Oh no!";

	size_t num_of_students = 0;

	file >> num_of_students;

	int scores[5];

	int *student_temp = new int[num_of_students];

	Student *students = new Student[num_of_students];
	

	for (size_t i = 0; i < num_of_students; ++i)
	{
		for (size_t j = 0; j < 5; ++j)
		{
			file >> scores[j];
		}
		students[i].fillScores(scores);
		student_temp[i] = students[i].calculateTotalScore();
	}
	
	int rez = std::count_if(student_temp + 1, student_temp + num_of_students,[student_temp](int student_sum){return student_sum > student_temp[0];});


	std::cout << rez << std::endl;

	delete [] student_temp;
	delete [] students;
	file.close();
}

void zad3()
{
	myVector vec;
	size_t n;
	std::cin >> n;
	int temp;
	for (size_t i = 0; i < n; ++i)
	{
		std::cin >> temp;
		vec.push_back(temp);
	}

	for (auto &i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
}