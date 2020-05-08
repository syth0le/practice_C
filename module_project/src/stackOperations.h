#ifndef STACKOPERATIONS_H_
#define STACKOPERATIONS_H_

/*
 There are functions which working with stack.
 1 - pop_stack function: get element from the top of the stack.
 2 - push_stack function: put operation result to the top of the stack.
*/


// announce work structure (stack for saving results after counting operations).
typedef struct rez_stack{
    float result;
    struct rez_stack *res_last;
}rez_stack;

float pop_stack(void);
void push_stack(float element);

#endif
