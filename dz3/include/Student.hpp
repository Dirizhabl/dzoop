#ifndef STUDENT_HPP
#define STUDENT_HPP

struct Student
{
    int scores[5];
    Student();
    void fillScores(int(& arr)[5]);
    int calculateTotalScore() const;
    void print() const;
};


#endif