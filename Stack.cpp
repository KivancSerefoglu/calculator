#include "Stack.h"

Stack::Stack(){
    head=nullptr;
}
Stack::~Stack(){
    delete head;
}

void Stack::push (StackItem *s){
    s->next = head;
    head = s;
}

StackItem* Stack::pop(){
    StackItem *temp;
    if (head==nullptr){
        cout<<"Stack is empty "<<endl;
        return nullptr;
    }
    temp = head;
    head = head->next;
    return temp;
}
StackItem* Stack:: top(){
    return head;
}
bool Stack:: isEmpty(){
     return head== nullptr;
}
