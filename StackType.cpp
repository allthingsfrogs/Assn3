#include <iostream>
#include "StackType.hpp"
using namespace std;

StackType::StackType() //Constructor
{
    topPtr = NULL;
}

StackType::~StackType() //Destructor
{
}

void StackType::Push(string input) //Adds to top of stack
{
    NodeType* location;
    location = new NodeType(); //allocate mem for new node
    location->data = input; //data assigned to user/file input
    location->next = topPtr; //topPtr is now the next node while this one is new topPtr;
    topPtr = location; //      ^^see
}

void StackType::Pop() //Removes from top of stack
{
    NodeType* tempPtr; 
    tempPtr = topPtr; //allocate mem for temp to hold topPtr
    topPtr = topPtr ->next; //make the topPtr == the next topmost pointer
    delete tempPtr; //delete tempPtr, now nextmost topPtr is the topPtr
    tempPtr = NULL; //just in case
}

string StackType::Top() //returns string at top of stack
{   
    return topPtr->data;
}


bool StackType::IsEmpty() const //returns true if empty
{
    return (topPtr == NULL); 
}

bool StackType::IsFull() const //returns true if stack is full
{
    NodeType* location;
    location = new NodeType;
    if (location != NULL) {
        delete location;
        return false;
    }
    else return true;
}
