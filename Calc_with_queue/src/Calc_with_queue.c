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
    char string[60];
    struct command_list *next;
}queue;

queue *head = NULL;
queue *tail = NULL;

// structure for results after operations
typedef struct rez_stack{
    float result;
    struct stack *res_last;
}rez_stack;

rez_stack *head_stack = NULL;


float pop_stack(void);
void push_stack(float element);
int putElement(FILE *input);
char getElement(void);
float numbers(char sign, float firstNum, float secondNum);


int main(void) {
    //int end_work = 1;
    int counting = 0;
    float elem1, elem2, elem3, rez;
    char inFile[100], outFile[100], *smth;
    FILE *input, *output;
    printf("Enter input file name: ");
    scanf(" %s", inFile);
    printf("Enter output file name: ");
    scanf(" %s", outFile);
    input = fopen(inFile, "r");
    while(!feof(input)){ // ec чо добавить в иф обратно
        putElement(input);
        counting += 1;
    }

}

float numbers(char oper, float a, float b){
    float rez;
    int var1, var2;
    switch (oper){

        case "+":
            rez = a + b;
            return rez;

        case "-":
            rez = a - b;
            return rez;

        case "*":
            rez = a * b;
            return rez;

        case "/":
            if (b == 0){
                return 0;
            }
            else{
                rez = a / b;
                return rez;
            }
        case '^':
            var2 = 1;
            var1 = 1;
            for (int ist1=1;ist1<=b[0];ist1++){
                var1 = var2;
                var2 = var1 * a[0];}
            rez[0] = var2;
            return rez;

        case '!':
            var1 = 1;
            for(int i = 1; i<=a[0]; i++)
            {var1 = var1 * i;}
            rez[0] = var1;
            return rez;
    }
}


int putElement(FILE *input){
    queue *tmp = malloc(1 * sizeof(queue));
    fgets(tmp->string, sizeof(tmp->string), input);
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

char *getElement(void){
    if(head != NULL) {
        char *data;
        data = head->string;
        head = head->next;
        return data;
    } else{return NULL;}
}


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
    if (head_stack != NULL){
    rez_stack *tmp;
    float data;
    tmp = head_stack;
    head_stack = head_stack->res_last;
    data = tmp->result;
    free(tmp);
    return data;}
    else{
        return NULL;
    }
}
