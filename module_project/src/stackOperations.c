#include <stdio.h>
#include "stackOperations.h"


typedef struct rez_stack{
    float result;
    struct rez_stack *res_last;
}rez_stack;

rez_stack *head_stack = NULL;

void push_stack(float element){
    rez_stack *tmp_stack = malloc(1* sizeof(rez_stack));
    tmp_stack->result = element;
    if (head_stack == NULL){
        tmp_stack->res_last = NULL;
        head_stack = tmp_stack;
    } else{
        tmp_stack->res_last = head_stack;
        head_stack = tmp_stack;
    }
}

float pop_stack(void){
    rez_stack *tmp;
    float data;
    tmp = head_stack;
    head_stack = head_stack->res_last;
    data = tmp->result;
    free(tmp);
    return data;
}
