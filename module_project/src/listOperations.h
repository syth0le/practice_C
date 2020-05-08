#ifndef LISTOPERATIONS_H_
#define LISTOPERATIONS_H_
#include <stdio.h>

/*
 There are functions which working with queue.
 1 - addelement function: add all elements to start_list, when program make reading from input file.
 2 - addelement_res function: add result after operations to re_list.
 3 - addnumber function: this function was made for reading pointer of number and adding him to variable
 4 - numbers_list function: counting simple numbers with memory allocation, which was written only for list operations.
*/


//announce work structure (list for saving elements from input file).
typedef struct start_list {
    char operation;
    char sign;
    int size;
    float *firstNum;
    float *secondNum;
    struct start_list *next;
} input_data;

//announce work structure (list for saving results after counting operations).
typedef struct rez_list {
    float *result;
    struct rez_list *res_next;
} output_data;

void addelement(input_data *current, FILE *input);
void addelement_res(output_data *current_res, input_data *current);
float *addnumber(FILE *input, int size);
float *numbers_list(char sign, float *firstNum, float *secondNum);

#endif /* LISTOPERATIONS_H_ */
