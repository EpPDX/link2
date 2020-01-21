/*


linked lists p1 
code by caley epstein

student list with many functions

.o file from kyle

i had a hard time with this one :( result isnt awesome. sorry it doesnt work. hopefully there's something worth points in here)
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iomanip>


#include "Node.h"
#include "Student.h"

using namespace std;




//node stuff, sets up for add information

void addNew(Node* previous,  Student* student);
void print(Node* next);
float average(Node* next);
void remove(Node* next, Node* previous, char name[]);

Node* first = NULL;


//main funct for selecting operation

int main() 
{
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  
  
  while (true) 
  {
    char input[10];
    int intInput;
    float floatInput;
    cout << "what do you want to do?" << endl;
    cin.get(input, 10);
    cin.clear();
    cin.ignore(1000000, '\n');


//if user wants to add, go collect all info and set variables
    if (strcmp(input, "add") == 0) 
    {
      Student* newStudent = new Student;
      cout << endl << "first name?" << endl;
      cin.get(newStudent -> get1(), 10);
      cin.clear();
      cin.ignore(1000000, '\n');
      
      cout << "last name?" << endl;
      cin.get(newStudent -> getL(), 10);
      cin.clear();
      cin.ignore(1000000, '\n');
      
      cout << "ID?" << endl;
      cin >> intInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      
      newStudent -> setID(intInput);
      cout << "GPA?" << endl;
      cin >> floatInput;
      cin.clear();
      cin.ignore(1000000, '\n');
    
    
    //add function  
      newStudent -> setGPA(floatInput);
      addNew(first, newStudent);
      cout << "added" << endl << endl;
    } 
    
    
    //pretty much print function
    else if (strcmp(input, "print") == 0) 
    {
      if (first == NULL) 
      {
	    cout << endl << "no students" << endl << endl;
      }
      else 
      {
	    cout << endl;
	    print(first);
      }
    }

    //delete has to deal w selecting who to delete
    else if (strcmp(input, "delete") == 0) 
    {
      if (first == NULL) 
      {
    	cout << endl << "no students" << endl << endl;
      }
      else 
      {
	    cout << endl << "first name?" << endl;
	    cin.get(input, 10);
	    cin.clear();
	    cin.ignore(1000000, '\n');
    	remove(first, NULL, input);
      }
    }
    
    //prints average gpa if there are any students
    else if (strcmp(input, "average") == 0) 
    {
      if (first == NULL) 
      {
    	cout << endl << "no students" << endl << endl;
      }
      else 
      {
    	cout << endl << "average GPA: " << average(first) << endl << endl;
      }
    }
    
    
    
    else if (strcmp(input, "quit") == 0) 
    {
      break;
    }
    
    //anthing else
    else 
    {
      cout << "Invalid Input" << endl;
    }
  }
  return 0;
}



//function to add with nodes
void addNew(Node* previous, Student* student) 
{
  
  
  if (first == NULL) 
  {
    first = new Node(student);
  }
  
  else if (student -> getID() < first -> getStudent() -> getID()) 
  {
    Node* temp = new Node(first -> getStudent());
    temp -> setNext(first -> getNext());
    first -> setStudent(student);
    first -> setNext(temp);
  }
  
  
  
  else if (student -> getID() < previous -> getNext() -> getStudent() -> getID()) 
  {
    Node* newNode = new Node(student);
    newNode -> setNext(previous -> getNext());
    previous -> setNext(newNode);
  }
  
  
  else if (previous -> getNext() == NULL) 
  {
    Node* newNode = new Node(student);
    previous -> setNext(newNode);
  }
  else 
  {
    addNew(previous -> getNext(), student);
  }
}





//function to delete with nodes
void remove(Node* next, Node* previous, char name[]) 
{
  char yn;
  if (next == first && strcmp(next -> getStudent() -> get1(), name) == 0) 
  {
    cout << endl << next -> getStudent() -> getL();
    cout << next -> getStudent() -> get1() << endl;
    cout << next -> getStudent() -> getID() << endl;
    cout << next -> getStudent() -> getGPA() << endl << endl;
    
    
    //if student needs to be deleted. stupid complex
    
    cout << "delete this student? (y/n)" << endl;
    cin >> yn;
    cin.clear();
    cin.ignore(1000000, '\n');
    
    
    if (yn == 'y') 
    {
      cout << "deleted" << endl << endl;
      if (next -> getNext() == NULL) 
      {
    	next -> ~Node();
    	first = NULL;
      }
     
     
      else 
      {
    	first = next -> getNext();
    	next -> ~Node();
    	remove(first, NULL, name);
      }
    }
    
    
    
    else if (yn == 'n') 
    {
      cout << "student not deleted" << endl << endl;
      if (next -> getNext() != NULL) 
      {
	remove(next -> getNext(), next, name);
      }
    }
    else 
    {
      cout << "?" << endl << endl;
    }
  }
  
  
  
  
  
  else if (strcmp(next -> getStudent() -> get1(), name) == 0) 
  {
    cout << endl << next -> getStudent() -> getL() << ", ";
    cout << next -> getStudent() -> get1() << endl;
    
    
    cout << "delete this student? (y/n)" << endl;
    cin >> yn;
    cin.clear();
    cin.ignore(1000000, '\n');
    
    
    if (yn == 'y') 
    {
      cout << "deleted" << endl << endl;
      previous -> setNext(next -> getNext());
      next -> ~Node();
    }
    
    else if (yn == 'n') 
    {
      cout << "student not deleted" << endl << endl;
    }
    else 
    {
      cout << "?" << endl << endl;
    }
  }
  
  
  
  if (next -> getNext() != NULL) 
  {
    remove(next -> getNext(), next, name);
  }
}


//print w node
void print(Node* next) 
{
  if (next != NULL) 
  {
    cout << next -> getStudent() -> getL();
    cout << next -> getStudent() -> get1() << endl;
    cout << next -> getStudent() -> getID() << endl;
    cout << next -> getStudent() -> getGPA() << endl << endl;
    print(next -> getNext());
  }
}


//averages for gpa average above

float average(Node* next) 
{
  float total = 0;
  int counter = 0;
  
  
  if (next == first) 
  {
    total += next -> getStudent() -> getGPA();
    
    counter++;
  }
  
  while (next -> getNext() != NULL) 
  {
    total += next -> getNext() -> getStudent() -> getGPA();
    
    counter++;
    next = next -> getNext();
  }
  return (total/counter);
}


/*




//inclusions and setup
#include <iostream>
#include <cstring>


#include "node.h"
#include "student.h" 

#include <stdio.h>
#include <iomanip>





using namespace std;

int main()
{
  //variables
  char input[20];

