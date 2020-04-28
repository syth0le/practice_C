/*
 ============================================================================
 Name        : Calc_with_list.c
 Author      : sythole
 Version     :
 Copyright   : my and only my
 Description : This new calc version. It works with data structures like lists.
 Using this calc is simple. Enter input and output files, program reads needful data from input file and starts working.
 From input file elements will add to first list and if program will need elements, it will get everything from start_list.
 After counting, results will add to another list.
 Finally, program read elements from rez_list and add everything to output file.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


// create useful data structures, which were described in task.
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

// all using functions in program, their realizations will be down below.
float *numbers(char sign, float *firstNum, float *secondNum);
float *vectors(char sign, int size, float *vector1, float *vector2);
float *addnumber(FILE *input, int size);
void addelement(input_data *current, FILE *input);
void addelement_res(output_data *current_res, input_data *current);


// main function using all functions writed from above.
int main() {
    int end_work = 1;
    char inFile[100], outFile[100];
    FILE *input, *output;
    input_data *head, *current;
    output_data *head_result, *current_result;
    while(end_work != 0){
    printf("Enter input file name: ");
    scanf(" %s", inFile);
    printf("Enter output file name: ");
    scanf(" %s", outFile);
    input = fopen(inFile, "r");
    if(!feof(input)){
        // it works until the end of input file appeared

        head = malloc(1 * sizeof(input_data));  // make memory allocation for head of our list. It will be for each element.
        fscanf(input, " %c %c", &head->sign, &head->operation);

        // process all data of each element
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

        // swapping current pointer element
        // it needs for future operations and for adding next head element when cycle will go to next round.
        current = head;
        int n;

        // adding elements until we get the end of file.
        while (!feof(input))
        {
            addelement(current, input);
            current = current->next;
            n += 1;
        }

        // make memory allocation for head of res_list.
        head_result = malloc(sizeof(output_data));

        // swap pointers for current.
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

        // adding all elements to res_list until elements end.
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

        // process all needful elements to res_list until elements end.
        // adding results to output file correctly.
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
    printf("Do you want to continue?\n");
    printf("Enter 0 - to close, any button for continue\n");
    scanf(" %i", &end_work);
    }
    return EXIT_SUCCESS;
}


// function for counting simple numbers with memory allocation
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

// function for counting vectors with memory allocation
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
    free(vector1);  // return needful results after counting and free all temporary vars.
    free(vector2);
    free(res_vect);
}

//This function was made for reading pointer of number and adding him to variable
float *addnumber(FILE *input, int size){
    float *number;
    number = malloc(size * sizeof(float));
    for(int i = 0;i < size;i++)
    {
        fscanf(input,"%f", &number[i]);
    }
    return number;
}

// function adding needful numbers to our created structure
// it reads instructions from input file and creates list with predefined actions
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

// this function is analog of "addelement". It's working principle is similar with upper func.
// but this function doesn't read something from file, it read needful numbers after all operations we did.
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

