#ifndef LISTOPERATIONS_H_
#define LISTOPERATIONS_H_
#include <stdio.h>

typedef struct start_list {
    char operation;
    char sign;
    int size;
    float *firstNum;
    float *secondNum;
    struct start_list *next;
} input_data;

typedef struct rez_list {
    float *result;
    struct rez_list *res_next;
} output_data;

void addelement(input_data *current, FILE *input);
void addelement_res(output_data *current_res, input_data *current);
float *addnumber(FILE *input, int size);
float *numbers_list(char sign, float *firstNum, float *secondNum);

#endif /* LISTOPERATIONS_H_ */
