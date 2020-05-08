#ifndef COUNTOPERATIONS_H_
#define COUNTOPERATIONS_H_

/*
 There are functions which working with simple numbers operations, vectors, indicated.
 1 - numbers function: multiplication'*', division'/', addition'+', subtraction'-', exponentiation'^', factorial'!'.
 2 - factorial function: counting factorial of number.
 3 - vectors function: vectors addition '+', vectors subtraction '-', scalar product of vectors '*'.
 Vector's func. supporting using different cord.systems in calculation operations.
*/

float numbers(char oper, float a, float b);
float factorial(float number);
float *vectors(char sign, int size, float *vector1, float *vector2);


#endif /* COUNTOPERATIONS_H_ */
