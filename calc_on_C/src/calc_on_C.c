/*
 ============================================================================
 Name        : simple_calc_on_C_final_ver.c
 Author      : syth0le
 Version     : 2.0
 Copyright   : my and only my
 Description : Calc on C.
 In 2nd version of program appears opportunity to do vector's calculations.
 You can choose work mode (1 - num.operations, 2- vector operations)
 In num. mode this calc can make different operations.
 There are multiplication'*', division'/', addition'+', subtraction'-', exponentiation'^', factorial'!' are supported.
 In this program realized function of cooperation with users.
 You can continue using calc or exit him, when request will be appeared.
 Vector's mode supporting using different cord.systems in calculation operations.
 There are presented different vector operations such as vectors addition, vectors subtraction, scalar product of vectors.
 update:
 This is 3rd version of calc on C. Supporting 2 modes: file-reading and console. If u want to read information from file, please follow some rules:
    1.Information format must be like: - s 3 2 or * v 3 4 5 5 -1 2 -7 on 1st place - operation type, then mode type(s - num. operations, v - vectors),
        if you choose number operations then enter 2 numbers, splitting space, or 1 number if u want counting factorial.
        if you choose vector operations then enter coordinate system type(n-dimensional), and then needful quantity of numbers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float firstNum, secondNum, var1, var2, result;  // main working vars
    int size;  // var for choosing operation type
    char choose, sign = '$', l, inFile[100], outFile[100], repeat = 'y';
    float *vector1, *vector2;
    FILE *input, *output;
    while(repeat == 'y'){
        printf("What do u want to use?\n Choose f - file, c - console.");
        printf("\nEnter your choice: ");
        scanf(" %c", &l);

        switch (l){
            case 'f':
                printf("\nEnter input file name: ");
                scanf("%s", inFile);
                printf("Enter output file name: ");
                scanf("%s", outFile);

                input = fopen(inFile, "r");
                output = fopen(outFile, "a");
                while (feof(input) == 0){
                fscanf(input, " %c", &sign);
                fscanf(input, " %c", &choose);

                switch(choose){
                    case 's':

                        switch(sign){

                            case '+':
                                fscanf(input, " %f %f", &firstNum, &secondNum);
                                fprintf(output, "(%.2f + %.2f) = %.2f", firstNum, secondNum, firstNum + secondNum);
                                break;

                            case '-':
                                fscanf(input, " %f %f", &firstNum, &secondNum);
                                fprintf(output, "(%.2f - %.2f) = %.2f", firstNum, secondNum, firstNum - secondNum);
                                break;

                            case '*':
                                fscanf(input, " %f %f", &firstNum, &secondNum);
                                fprintf(output, "(%.2f * %.2f) = %.2f", firstNum, secondNum, firstNum * secondNum);
                                break;

                            case '/':
                                fscanf(input, " %f %f", &firstNum, &secondNum);
                                if (secondNum != 0)
                                    fprintf(output, "(%.2f / %.2f) = %.2f",firstNum, secondNum, firstNum / secondNum);
                                else fprintf(output, "mistake!U can't divide into 0\n");
                                break;

                            case '^':
                                fscanf(input, " %f %f", &firstNum, &secondNum);
                                var2 = 1;
                                var1 = 1;
                                for (int ist1=1;ist1<=secondNum;ist1++){
                                    var1 = var2;
                                    var2 = var1 * firstNum;}
                                fprintf(output, "%.2f ^ %.2f = %.2f", firstNum, secondNum, var2);
                                break;

                            case '!':
                                fscanf(input, "%f",&firstNum);
                                if (firstNum >= 0) {
                                    var1=0;
                                    var2=1;
                                    for (int ist1=1; ist1<=firstNum;ist1++){
                                        var2 = var2 * ist1;
                                        var1 = var2;}
                                    fprintf(output, "%.0f! = %.0f", firstNum, var2);}
                                else fprintf(output, "This operation is not valid");
                                break;

                            default:
                                fprintf(output, "Unknown operation, try again.");
                                break;
                        }
                        break;

                    case 'v':
                        fscanf(input, "%i",&size);
                        vector1 = malloc(size*sizeof(int));
                        vector2 = malloc(size*sizeof(int));
                        for (int i=0; i < size; i++) fscanf(input, "%f", &vector1[i]);
                        for (int i=0; i < size; i++) fscanf(input, "%f", &vector2[i]);

                        switch(sign){

                            case '+':
                                fprintf(output, "( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", vector1[i]);
                                fprintf(output, " ) + ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", vector2[i]);
                                fprintf(output, " ) = ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", vector1[i] + vector2[i]);
                                fprintf(output, " )");
                                break;

                            case '-':
                                fprintf(output, "( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", vector1[i]);
                                fprintf(output, " ) - ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", vector2[i]);
                                fprintf(output, " ) = ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", vector1[i] - vector2[i]);
                                fprintf(output, " )");
                                break;

                            case '*':
                                fprintf(output, "( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", vector1[i]);
                                fprintf(output, " ) * ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", vector2[i]);
                                fprintf(output, " ) = ");
                                for (int i=0; i < size; i++) result += vector1[i] * vector2[i];
                                fprintf(output, "%.2f ", result);
                                break;

                            default:
                                fprintf(output, "Unknown operation");
                        }
                        free(vector1);
                        free(vector2);
                        break;

                    default:
                        fprintf(output, "This unsupportable mode. Well, try again, follow descriptions.");
                }
                fprintf(output, "\n");
                }
                fclose(input);
                fclose(output);
                break;

            case 'c':
                sign = '$';
                printf("Choose calc mode: ");
                printf("1 - num. operations, 2 - vector operations: ");
                scanf(" %c", &choose);
                if (choose == '1'){
                    printf("type first number: "); // typing first number
                    scanf(" %f%*c", &firstNum);
                    while(sign == '$'){
                        printf("type sign from range('+', '-', '*', '/', '^', '!'): ");
                        scanf("%c%*c", &sign); // typing sign of the operation
                        switch (sign) {

                            case '+': // typing '+' for addition
                                printf("type second number:"); // typing second number
                                scanf("%f%*c", &secondNum);
                                printf("%.2f\n", firstNum+secondNum);
                                break;

                            case '-': // typing '-' for subtraction
                                printf("type second number:"); // typing second number
                                scanf("%f%*c", &secondNum);
                                printf("%.2f\n", firstNum-secondNum);
                                break;

                            case '*': // typing '*' for multiplication
                                printf("type second number:"); // typing second number
                                scanf("%f%*c", &secondNum);
                                printf("%.2f\n", firstNum*secondNum);
                                break;

                            case '/': // typing '/' for division
                                printf("type second number:"); // typing second number
                                scanf("%f%*c", &secondNum);
                                if (secondNum != 0) {
                                    printf("%.2f\n", firstNum/secondNum);}
                                else printf("mistake!U can't divide into 0\n");
                                break; // if u divide into 0 there is error message will be appeared

                            case '^': // typing '^' for exponentiation
                                printf("type second number:"); // typing second number
                                scanf("%f%*c", &secondNum);
                                var2 = 1;
                                var1 = 1;
                                for (int ist1=1;ist1<=secondNum;ist1++){
                                    var1 = var2;
                                    var2 = var1 * firstNum;}
                                printf("%.2f\n", var2);
                                break;

                            case '!': // typing '!' for factorial
                                if (firstNum >= 0){
                                    var1=0;
                                    var2=1;
                                    for (int ist1=1; ist1<=firstNum;ist1++){
                                        var2 = var2 * ist1;
                                        var1 = var2;}
                                    printf("%.2f\n", var2);}
                                else printf("This operation is not valid, try again.");
                                break;

                            default:
                                printf("Unsupportable sign.Please, type another from this range: +, -, *, /, ^, !.\n");
                                sign = '$';
                        }
                    }
                }
                else if (choose == '2'){             //choosing coordinate system
                    printf("Type vector's size: ");
                    scanf("%i", &size);
                    vector1 = malloc(size*sizeof(float));
                    if (size == 2){
                        printf("Enter 2 cords of vector (a): x,y and then choose operation.\n");
                    }
                    if (size == 3){
                        printf("Enter 3 cords of vector (a): x,y,z and then choose operation.\n");
                    }
                    for (int i = 0; i < size; i++) {
                        int j = 1 + i;
                        printf("Enter ");
                        printf("%i", j);
                        printf(" cord: " );
                        scanf("%f", &vector1[i]);
                    }
                    while(sign == '$'){
                        vector2 = malloc(size*sizeof(float));
                        printf("type sign from range: \n");
                        printf("'+'-vectors addition,");
                        printf("'-'-vectors subtraction");
                        printf("'*'- scalar product of vectors\n");
                        scanf(" %c%*c", &sign);
                        if (size == 2){
                            printf("Enter 2 cords of vector (b): x,y and then waiting for calculation result.\n");
                        }
                        if (size == 3){
                            printf("Enter 3 cords of vector (b): x,y,z and then waiting for calculation result.\n");
                        }
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
                                    result += vector1[i] * vector2[i];// counting vector's operations in cycle 'for'
                                }
                                printf("\n Result: %.2f\n\n", result);
                                break;

                            default:
                                printf("unsupportable sign. \nPlease, type another from this range:\n");
                                printf("'+'-vectors addition, \n");
                                printf("'-'-vectors subtraction \n");
                                printf("'*'- scalar product of vectors \n");
                                sign = '$';
                        }
                    }
                    free(vector1);
                    free(vector2);
                }
                else{
                    printf("Unsupportable mode type.\nChoose from this list:");
                    printf("1 - num. operations, 2 - vector operations");
                }
            sign = '$';
            break;

            default:
                printf("This unsupportable mode. Try again, follow descriptions.\n");
                break;
        }
        printf("Do you want to continue? Enter y to continue any button to close: ");
        scanf(" %c", &repeat);
    }
}
