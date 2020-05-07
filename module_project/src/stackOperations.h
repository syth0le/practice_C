#ifndef STACKOPERATIONS_H_
#define STACKOPERATIONS_H_

typedef struct rez_stack{
    float result;
    struct rez_stack *res_last;
}rez_stack;

float pop_stack(void);
void push_stack(float element);

#endif
