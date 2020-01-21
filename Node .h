
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;



#endif


class Node
{
public:
  Node ();		
  Node ();	
  
  
  void setValue (int newvalue);
  int getValue ();	
  void setNext (Node * nextnext);
  Node *getNext ();		
private:
  int value;
  Node *next;
};
