/*
 ============================================================================
 Name        : Calc_with_list.c
 Author      : sythole
 Version     :
 Copyright   : my and only my
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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
    free(firstNum);
    free(secondNum);
    free(res_num);
}


float *vectors(char sign, int size, float *vector1, float *vector2){
    float *res_vect;
    switch (sign){
        case '+':
            res_vect = malloc(size * sizeof(float));
            for (int i = 0; i < size; i++)
            {
                res_vect[i] = vector1[i] + vector2[i];
            }
            return res_vect;
        case '-':
            res_vect = malloc(size * sizeof(float));
            for (int i = 0; i < size; i++)
            {
                res_vect[i] = vector1[i] - vector2[i];
            }
            return res_vect;
        case '*':
            res_vect = malloc(1 * sizeof(float));
            res_vect[0] = 0;
            for (int i = 0; i < size; i++)
            {
                res_vect[0] = res_vect[0] + (vector1[i] * vector2[i]);
            }
            return res_vect;
        }
    return vector1;
    return vector2;
    free(vector1);
    free(vector2);
    free(res_vect);
}

float *addnumber(FILE *input, int size){ //Добавление числа
    float *number;
    number = malloc(size * sizeof(float));
    for(int i = 0;i < size;i++)
    {
        fscanf(input,"%f", &number[i]);
    }
    return number;
}

void addelement(input_data *current, FILE *input){
    input_data *tmp = malloc(1 * sizeof(input_data));
    fscanf(input, " %c %c", &tmp->sign, &tmp->operation);
    if (tmp->operation == 'v'){
        fscanf(input, " %i", &tmp->size);}
    else{
        tmp->size = 1;
    }
    if (tmp->sign != '!')
    {
        tmp->firstNum = addnumber(input, tmp->size);
        tmp->secondNum = addnumber(input, tmp->size);
    }
    else
    {
        tmp->firstNum = addnumber(input, tmp->size);
        tmp->secondNum = NULL;
    }
    tmp->next = NULL;
    current->next = tmp;
}

void addelement_res(output_data *current_res, input_data *current)
{
    output_data *tmp_res = malloc(1 * sizeof(output_data));
    if (current->operation == 'v'){
        tmp_res->result = vectors(current->sign, current->size, current->firstNum, current->secondNum);
    }
    else{
        tmp_res->result = numbers(current->sign, current->firstNum, current->secondNum);
    }
    tmp_res->res_next = NULL;
    current_res->res_next = tmp_res;
}


int main() {
    char inFile[100], outFile[100];
    FILE *input, *output;
    input_data *head, *current;
    output_data *head_result, *current_result;
    printf("Enter input file name: ");
    scanf(" %s", inFile);
    printf("Enter output file name: ");
    scanf(" %s", outFile);
    input = fopen(inFile, "r");
    if(!feof(input)){
        head = malloc(1 * sizeof(input_data));
        fscanf(input, " %c %c", &head->sign, &head->operation);
        if (head->operation == 'v') { fscanf(input, " %i", &head->size);
        }
        else
        {
            head->size = 1;
        }
        if (head->sign != '!') {
            head->firstNum = addnumber(input, head->size);
            head->secondNum = addnumber(input, head->size);
        }
        else
        {
            head->firstNum = addnumber(input, head->size);
            head->secondNum = NULL;
        }
        current = head;
        int n;
        while (!feof(input))
        {
            addelement(current, input);
            current = current->next;
            n += 1;
        }
        head_result = malloc(sizeof(output_data));
        current = head;
        if (current->operation == 'v')
        {
            head_result->result = vectors(current->sign, current->size, current->firstNum, current->secondNum);
        }
        else
        { head_result->result = numbers(current->sign, current->firstNum, current->secondNum); }
        head_result->res_next = NULL;
        current = current->next;
        current_result = head_result;
        while (current != NULL)
        {
            addelement_res(current_result, current);
            current = current->next;
            current_result = current_result->res_next;
        }
        current = head;
        current_result = head_result;
        fclose(input);
        output = fopen(outFile, "w");
        while (current != NULL) {
            if (current->operation == 'v') {
                fprintf(output, "(");
                //вывод данных из first,second and result
                for (int i = 0; i < current->size; i++) {
                    fprintf(output, " %.2f ", current->firstNum[i]);
                }
                fprintf(output, ") %c (", current->sign);
                for (int i = 0; i < current->size; i++) {
                    fprintf(output, " %.2f ", current->secondNum[i]);
                }
                fprintf(output, ") = ");
                if (current->sign != '*') {
                    fprintf(output, "(");
                    for (int i = 0; i < current->size; i++) { fprintf(output, " %.2f ", current_result->result[i]); }
                    fprintf(output, ")\n");
                } else {
                    fprintf(output, " %.2f\n", current_result->result[0]);
                }
            } else if (current->operation == 's'){
                fprintf(output, "%.2f\n", current_result->result[0]);
           }
            current = current->next;
            current_result = current_result->res_next;
        }
        fclose(output);
    }
    return EXIT_SUCCESS;

}
