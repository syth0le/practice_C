/*
 ============================================================================
 Name        : Calc_with_queue.c
 Author      : sythole
 Version     :
 Copyright   : my and only my
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//structure for strings.
typedef struct command_list{
    char command[60];
    struct command_list *next;
}queue;

queue *head = NULL;
queue *tail = NULL;

// structure for results after operations
typedef struct stack {
    float result;
    struct stack *res_last;
} rez_stack;

rez_stack *head_stack = NULL;


float pop_stack(void);
void push_stack(float element);
int addelement_queqe(FILE *input);
char *read_element(void);
float *numbers(char sign, float *firstNum, float *secondNum);


int main(void) {
	puts("zdarova"); /* p
	rints zdarova */
	return EXIT_SUCCESS;
}


float *numbers(char sign, float *firstNum, float *secondNum){
    float *res_num;
    float var1, var2;
    res_num = malloc(1 * sizeof(float));
    switch (sign) {
        case '+':
            res_num[0] = firstNum[0] + secondNum[0];
            return res_num;

        case '-': // typing '-' for subtraction
            res_num[0] = firstNum[0] - secondNum[0];
            return res_num;

        case '*': // typing '*' for multiplication
            res_num[0] = firstNum[0] * secondNum[0];
            return res_num;

        case '/':
            if (secondNum[0] != 0) {
                res_num[0] = firstNum[0] / secondNum[0];
                return res_num;
            }
            else {
                return 0;
            }

        case '^':
            var2 = 1;
            var1 = 1;
            for (int ist1=1;ist1<=secondNum[0];ist1++){
                var1 = var2;
                var2 = var1 * firstNum[0];}
            res_num[0] = var2;
            return res_num;

        case '!':
            var1 = 1;
            for(int i = 1; i<=firstNum[0]; i++)
            {var1 = var1 * i;}
            res_num[0] = var1;
            return res_num;
    }
    return firstNum;
    return secondNum;
    free(firstNum);  // return needful results after counting and free all temporary vars.
    free(secondNum);
    free(res_num);
}


int addelement_queqe(FILE *input){
    queue *tmp = malloc(1 * sizeof(queue));
    fgets(tmp->command, sizeof(tmp->command), input);
    tmp->next = NULL;
    if(tail != NULL){
        tail->next = tmp;
        tail = tmp;
    } else{
        head = tmp;
        tail = tmp;
    }
    return 1;
}

char *read_element(void){
    if(head != NULL) {
        char *data;
        data = head->command;
        head = head->next;
        return data;
    } else{return NULL;}
}

//функция добавления в стэк
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

//Функция изъятия из стэка
float pop_stack(void){
    rez_stack *tmp;
    float data;
    tmp = head_stack;
    head_stack = head_stack->res_last;
    data = tmp->result;
    free(tmp);
    return data;
}
