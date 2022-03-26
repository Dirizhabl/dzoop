#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>

Student::Student(){}
void Student::fillScores(int(&arr)[5])
{
    for (size_t i = 0; i < 5; ++i)
    {
        scores[i] = arr[i];
    }
}

int Student::calculateTotalScore()const
{
    return std::accumulate(scores, scores + 5,0);
}

void Student::print()const
{
    for (auto &&v : scores)
    {
        std::cout << v << " ";
    }
    
    std::cout << std::endl;
}

