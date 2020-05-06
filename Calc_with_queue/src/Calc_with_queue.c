/*
 ============================================================================
 Name        : Calc_with_queue.c
 Author      : sythole
 Version     : calc version with queue and stack
 Copyright   : my and only my
 Description : This calculator has realized using queue and stack. Firstly, for correct work, fill in input file like this:
    | 4 5 -       | File must be filled using reverse polish notation instructions for number's operations. Let's for example describe second line:
    | 7 2 3 * -   |  1) first operation will be multiplication between 2 and 3: 2*3 = 6. 2) Second one will be subtraction between 7 and 6: 7-6 = 1.
    | 2 !         |  Finally we get the result 1. - this number will be added to stack for the following writing to output file.
    | #           |  WARNING! for correct calc work, please, type # into end line. This symbol means end of reading from input file.
    That's all. Follow program instructions (enter input and output files, which must be in such repository as main program file) and get needful result.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//queue for strings were got from file.
typedef struct command_list{
    char string[30];
    struct command_list *next;
}queue;

queue *head = NULL;
queue *tail = NULL;

// stack for saving results after operations.
typedef struct rez_stack{
    float result;
    struct rez_stack *res_last;
}rez_stack;

rez_stack *head_stack = NULL;

// announcing all functions. their realization shows down below.
float pop_stack(void);
void push_stack(float element);
int putElement(FILE *input);
char *getElement(void);
float numbers(char sign, float firstNum, float secondNum);


int main(void) {
    //int end_work = 1;
    int counting = 0;
    int k = 0, len = 0, m = -1;
    double a[30];
    float elem1, elem2, elem3, rez;
    char inFile[100], outFile[100], *smth, *cut, lol[10] = " ";
    FILE *input, *output;
    printf("Enter input file name: ");
    scanf(" %s", inFile);
    printf("Enter output file name: ");
    scanf(" %s", outFile);
    input = fopen(inFile , "r");

    // read from file strings to queue until file end.
    while(!feof(input)){
        putElement(input);
        counting++; // counting quantity of strings in queue.
    }

    // for each string do needful actions.
    while(counting != 0){
        smth = getElement(); // get string from queue.
        len = strlen(smth);  // counting string's len.
        counting--;

        while (counting != 0){
                counting--;
                cut = strtok(smth,lol); // divide the line into massive by spaces.
                while (cut != NULL)
                {
                    int i = 0;

                    // transfer string to float.
                    // if function can transfer it return float-number .
                    // if can't return 0.
                    elem1 = strtof(cut, NULL);
                    if (elem1 != 0){
                        push_stack(elem1); // push element to stack
                        i++;
                    }
                    else{
                        while(k <= len-1){
                        if(smth[k] == '+' || smth[k] == '-' || smth[k] == '*' || smth[k] == '/' || smth[k] == '^' || smth[k] == '!'|| smth[k] == '#'){
                            if (smth[k] == '#') {
                                k++;}
                            else{
                                if(smth[k] != '!'){
                                    // get two elements from stack and use number's operations function.
                                    // pushing result to stack.
                                    elem2 = pop_stack();
                                    elem1 = pop_stack();
                                    rez = numbers(smth[k], elem1, elem2);
                                    push_stack(rez);
                                    k++;
                                    }
                                else{
                                    // for factorial get only one number from stack .
                                    // and after operation put result to stack.
                                    elem1 = pop_stack();
                                    rez = numbers(smth[k], elem1, elem2);
                                    push_stack(rez);
                                    k++;
                                }
                            }
                        }
                        else{k++;}
                        }
                    }

                    cut = strtok (NULL, lol);
                }
                k = 0;
                smth = getElement(); // get next string for var: smth.
                len = strlen(smth); // counting len for current string
        }
    }
        // open output file for writing to it.
        output = fopen(outFile, "w");

        //getting elements from stack and adding them for correct reverse output.
        while (head_stack != NULL){
            m++;
            elem3 = pop_stack();
            a[m] = elem3;}

        // using reverse iteration for turning rezults around.
        for(k=m; k >= 0; k--) {
            fprintf(output, "Result: %.2f\n", a[k]);}

        // close working files.
        fclose(output);
        fclose(input);
}


// number's operations function.
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

// function for putting strings from file into queue.
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

// function for getting strings queue for the following actions.
char *getElement(void){
    if(head != NULL) {
        char *data;
        data = head->string;
        head = head->next;
        return data;
    } else{return NULL;}
}


//function for pushing to stack elements.
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

//function for getting to stack elements.
//it get element and delete it from stack.
float pop_stack(void){
    rez_stack *tmp;
    float data;
    tmp = head_stack;
    head_stack = head_stack->res_last;
    data = tmp->result;
    free(tmp);
    return data;
}


