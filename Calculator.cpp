#include "Calculator.h"

Calculator:: Calculator(string inFix) {
    this->infixExpression = inFix;
    this->postfixExpression="";
    stack= new Stack();

    //convert to postfix
    string token;
    istringstream  iss(infixExpression);
    iss >> token;
    while (token.compare(";") != 0){
        StackItem *newItem = new StackItem(token);
        if (newItem-> isOperator){
            if (stack->isEmpty() || newItem->op == OPERATOR_LEFTPAR ){
                stack->push(newItem);
            }else if (newItem-> op == OPERATOR_RIGHTPAR){
                while (stack->top()->op != OPERATOR_LEFTPAR || stack->top()==nullptr){
                    postfixExpression += stack->pop()->toString()+" ";
                } stack->pop();
            } else if(newItem->op <= stack->top()->op) {
                while(true){
                    postfixExpression += stack->pop()->toString()+ " ";
                    if (stack->isEmpty()){
                        break;
                    }else if (newItem->op > stack->top()->op){
                        break;
                    }
                }
                stack->push(newItem);
        }else{
                stack->push(newItem);
            }
        }else{
            postfixExpression += newItem->toString() + " ";
        }

        iss >> token;
    }

    while (!stack->isEmpty()){
        postfixExpression += stack->pop()->toString()+" ";
    }

    postfixExpression += ";";

}
Calculator::~Calculator(){
   delete stack;
}
string Calculator::getPostfix(){
    return postfixExpression;
}
int Calculator::calculate(){
    this->postfixExpression=getPostfix();
    stack= new Stack();
    string token;
    istringstream  iss(postfixExpression);
    iss >> token;
    while (token.compare(";") != 0){
        StackItem *newItem = new StackItem(token);
        int willPushedInt;
        if (newItem-> isOperator){
            int popped1 = stack->pop()->n;
            int popped2 = stack->pop()->n;
            if(newItem->op == 2){
                willPushedInt = popped2-popped1;
            } else if (newItem->op == 3){
                willPushedInt = popped2 + popped1;
            }else if (newItem->op == 4){
                willPushedInt = popped2 / popped1;
            }else if (newItem->op == 5){
                willPushedInt = popped2 * popped1;
            }
            StackItem *willPushed = new StackItem(false, willPushedInt);
            stack->push(willPushed);

        }else{
            stack->push(newItem);
        }
        iss >> token;
    }
    return stack->top()->n;
}
