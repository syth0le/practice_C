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
#include <string.h>

//structure for strings.
typedef struct command_list{
    char string[30];
    struct command_list *next;
}queue;

queue *head = NULL;
queue *tail = NULL;

// structure for results after operations
typedef struct rez_stack{
    float result;
    struct rez_stack *res_last;
}rez_stack;

rez_stack *head_stack = NULL;


float pop_stack(void);
void push_stack(float element);
int putElement(FILE *input);
char *getElement(void);
float numbers(char sign, float firstNum, float secondNum);


int main(void) {
    //int end_work = 1;
    int counting = 0;
    int k = 0, len = 0;
    float elem1, elem2, elem3, rez;
    char inFile[100], outFile[100], *smth, *cut, lol[10] = " ";
    FILE *input, *output;
    printf("Enter input file name: ");
    scanf(" %s", inFile);
    printf("Enter output file name: ");
    scanf(" %s", outFile);
    input = fopen(inFile , "r");
    printf("/0/");
    while(!feof(input)){
        putElement(input);
        counting += 1;
        printf("/1/");
    }
    while(counting != 0){
        printf("/2/");
        smth = getElement();
        //printf(smth);

        while (smth != NULL){
                cut = strtok(smth,lol);
                len += strlen(cut);
                k += (len / 2) + 1;

                while (cut != NULL)
                {

                    int i = 0;
                    elem1 = strtof(cut, NULL);
                    if (elem1 != 0){
                        k += 2;
                        push_stack(elem1);
                        i++;
                    }
                    else{
                        printf("/3/");
                        printf("{%c\n}", smth[k]);
                        if (smth[k] == '#') {
                            k = 0;
                            printf("break");
                            break;}
                        else if(smth[k] == '+' || smth[k] == '-' || smth[k] == '*' || smth[k] == '/' || smth[k] == '^' || smth[k] == '!'){
                            printf("/4/");
                            if(smth[k] != '!'){
                                printf("/5/");
                             elem2 = pop_stack();
                             elem1 = pop_stack();
                            }else{
                                printf("/6/");
                             elem1 = pop_stack();}
                            printf("/7/");
                            rez = numbers(smth[k], elem1, elem2);
                            push_stack(rez);
                            k += 2;
                            }
                    }
                    cut = strtok (NULL, lol);
                }
            printf("/9/");
            smth = getElement();
            k = 0;
        }
        counting -= 1;
    }
        output = fopen(outFile, "w");
        printf("/@/");
        while (head_stack != NULL){
            elem3 = pop_stack();
            fprintf(output, "Result: %.2f\n", elem3);
        }
        fclose(output);

    fclose(input);
}



float numbers(char oper, float a, float b){
    float rez;
    float var1, var2;
    switch (oper){

        case '+':
            rez = a + b;
            return rez;

        case '-':
            rez = a - b;
            return rez;

        case '*':
            rez = a * b;
            return rez;

        case '/':
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
            for (int ist1=1;ist1<=b;ist1++){
                var1 = var2;
                var2 = var1 * a;}
            rez = var2;
            return rez;

        case '!':
            var1 = 1;
            for(int i = 1; i<=a; i++)
            {var1 = var1 * i;}
            rez = var1;
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
    rez_stack *tmp;
    float data;
    tmp = head_stack;
    head_stack = head_stack->res_last;
    data = tmp->result;
    free(tmp);
    return data;
}


