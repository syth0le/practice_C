/*
 ============================================================================
 Name        : module_project.c
 Author      : syth0le
 Version     : 1.1 -adding documentation.
 Copyright   : my and only my.
 Description : This calculator has realized by modules. There are all needful functions, methods placed by files.
 1 - countigOperations - working with simple numbers operations and vectors.
 2 - queueOperations - working with queue.
 3 - stackOperations - includes functions which works with stacks.
 4 - listOperations - code-file which include functions working lists.
 NOTICE! For correct main file work there was created 2 modes: console and file inputs.
 Program suggested u modes and u can do needful choice.
 There are created 2 calc realizations in file mode: 1) q - queue and stack version 2) l - list version.
 FOR EACH NEEDFUL INPUT FILES WERE CREATED:
 >>>>> 1) input_q.txt - for queue and stack ver. (output_q.txt - output file)
 >>>>> 2) input_l.txt - for list ver. (output_l.txt - output file)
 Be attentive when work with files mode.
 1)-queue and stack version use reverse polish notation instructions.(works only with numbers)
 2)-list version use simple instructions like ((* v 2 3 4 5 6) - for vectors, (+ s 23 56) - for numbers)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countOperations.h"
#include "queueOperations.h"
#include "stackOperations.h"
#include "listOperations.h"




int main(void) {
    int size, k = 0, len = 0, m = -1, counting = 0, turn_on = 1, wf = 0;
    double a[30];
    float elem1, elem2, elem3, rez, *vector1, *vector2;
    char inFile[100], outFile[100], *smth, *cut, lol[10] = " ", mode, version, sign;
    FILE *input, *output;
    input_data *head, *current;
    output_data *head_result, *current_result;

    printf("Choose mode type c - console, f - file: ");
    scanf(" %c", &mode);

    switch(mode){

        case 'c':

            // console mode realization
            while(turn_on != 0){
                printf("Choose calc. version");
                printf("\nn - numbers, v - vectors: ");
                scanf(" %c", &version);
                switch(version){

                    case 'n':

                        printf("\nEnter first number: ");
                        scanf(" %f", &elem1);
                        printf("\nEnter operation (+ - * / ! ^): ");
                        scanf(" %c", &sign);
                        if(sign != '!'){
                            printf("\nEnter second number: ");
                            scanf(" %f", &elem2);
                            rez = numbers(sign, elem1, elem2);
                        }
                        else{
                            rez = factorial(elem1);
                        }
                        printf("\n Result: %.2f\n\n", rez);
                        break;

                    case 'v':

                        //choosing coordinate system
                        printf("Type vector's size: ");
                        scanf("%i", &size);
                        vector1 = malloc(size*sizeof(float));

                        for (int i = 0; i < size; i++) {
                           int j = 1 + i;
                           printf("Enter ");
                           printf("%i", j);
                           printf(" cord: " );
                           scanf("%f", &vector1[i]);
                        }
                        vector2 = malloc(size*sizeof(float));
                        printf("type sign from range: \n");
                        printf("'+'-vectors addition,");
                        printf("'-'-vectors subtraction");
                        printf("'*'- scalar product of vectors\n");
                        scanf(" %c%*c", &sign);
                        for (int i = 0; i < size; i++) {
                           int j = i + 1;
                           printf("Enter ");
                           printf("%i", j);
                           printf(" cord: " );
                           scanf("%f", &vector2[i]);
                        }
                        switch (sign) {

                           case '+':
                               printf("\n Result: ("); // counting vector's operations in cycle 'for'
                               for (int i = 0; i < size; i++){
                                   printf("%.2f", vector1[i] + vector2[i]);
                                   if (i != size-1) printf(" ");
                               }
                               printf(")\n\n");
                               break;

                           case '-':
                               printf("\n Result: ("); // counting vector's operations in cycle 'for'
                               for (int i = 0; i < size; i++){
                                   printf("%.2f", vector1[i] + vector2[i]);
                                   if (i != size-1) printf(" ");
                               }
                               printf(")\n\n");
                               break;

                           case '*':
                               for (int i = 0; i < size; i++) {
                                   rez += vector1[i] * vector2[i];// counting vector's operations in cycle 'for'
                               }
                               printf("\n Result: %.2f\n\n", rez);
                               break;

                           default:
                               printf("unsupportable sign.");
                        }
                        free(vector1);
                        free(vector2);
                        break;}
                printf("\nDo you want to continue to use console mode?\n");
                printf("Enter 0 - to close, any button for continue: ");
                scanf(" %i", &turn_on);
            }
            break;

        case 'f':

            // file reading mode realization.
            printf("Choose calc. version");
            printf("\nq - queue and stack, l - list: ");
            scanf(" %c", &version);
            printf("\nEnter input file name: ");
            scanf(" %s", inFile);
            printf("\nEnter output file name: ");
            scanf(" %s", outFile);
            input = fopen(inFile , "r");
            switch(version){

                // version with stack and queue.
                case 'q':
                    // read from file strings to queue until file end.
                    while(!feof(input)){
                        putElement(input);
                        counting++; // counting quantity of strings in queue.
                    }
                    wf = counting - 1;
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
                                                    rez = factorial(elem1);
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
                        while (wf != 0){
                            m++;
                            elem3 = pop_stack();
                            a[m] = elem3;
                            wf--;}

                        // using reverse iteration for turning rezults around.
                        for(k=m; k >= 0; k--) {
                            fprintf(output, "Result: %.2f\n", a[k]);}
                        // close working files.
                        fclose(output);
                        fclose(input);
                        break;

///////////////////////////////////////////////////////////////
                // version with lists.
                case 'l':
                    if(!feof(input)){
                        // it works until the end of input file appeared
                        head = malloc(1 * sizeof(input_data));  // make memory allocation for head of our list. It will be for each element.
                        fscanf(input, " %c %c", &head->sign, &head->operation);

                        // process all data of each element
                        if (head->operation == 'v') { fscanf(input, " %i", &head->size);}
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
                        {
                            head_result->result = numbers_list(current->sign, current->firstNum, current->secondNum); }
                        head_result->res_next = NULL;
                        current = current->next;
                        current_result = head_result;
                        // adding all elements to res_list until elements end.
                        while (current != NULL)
                        {
                            addelement_res(current_result, current);
                            current = current->next;
                            current_result = current_result->res_next;
                            counting++;
                        }
                        current = head;
                        current_result = head_result;
                        fclose(input);
                        output = fopen(outFile, "w");

                        // process all needful elements to res_list until elements end.
                        // adding results to output file correctly.
                        while (counting != 0) {
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
                            counting--;
                        }
                        fclose(output);
                        }
                    break;
                default:
                    printf("incorrect version type.");
                    break;}
            break;

        default:
            printf("incorrect mode type. Try again.");
            break;
    }
}
