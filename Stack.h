#ifndef __STACK__
#define __STACK__

#include "StackItem.h"
#include <iostream>

class Stack{

private:
    StackItem *head;
public:
    Stack();
    ~Stack();
    void push(StackItem*);
    StackItem* pop();
    StackItem* top();
    bool isEmpty();


};

#endif