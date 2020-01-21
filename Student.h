//student .h file for s data

#ifndef student_h
#define student_h

#include <iostream>
#include <cstring>

using namespace std;

class Student 
{
    public:
    Student();
    Student();
    char* getFirst();
    char* getLast();
    
    
    int getID();
    void setID(int);
    void setGPA(float);
    private:
    float getGPA();
    char first[10];
    char last[10];
    int ID;
    float GPA;
};




#endif