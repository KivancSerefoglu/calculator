In this assignment you will write a C++ program that evaluates an arithmetic expression (represented with an infix notation), then outputs this expression in postfix form and also outputs the result of the calculation. The program will first convert the input infix expression to a postfix expression (using the Stack ADT) and then calculate the result (again, using the Stack ADT). The details are provided in the following sections.

1) Input and Expected Output
The program will ask for an arithmetic expression in infix form. All the operators and
operands of the input expression should be separated with a space character and the
expression should end with a ‘;’ character. The input format is strict to be able to parse
the expression easily. The program will first print out the input expression in postfix
form, following the same formatting rules. Then, the result of the arithmetic expression
will be printed. A sample run of the program can be as follows. More test cases are
provided at the end of the document. The parts with bold face represent the user input.
Enter an arithmetic expression: 4 * 1 + 5 + 6 * 1 ;
Input expression in postfix form: 4 1 * 5 + 6 1 * + ;
The result is: 15
The program should support the basic four operators (i.e., +, -, *, /) and the use of
parenthesis.
IMPORTANT: The program should be commented out properly for each functionality

