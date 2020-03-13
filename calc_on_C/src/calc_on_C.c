/*
 ============================================================================
 Name        : simple_calc_on_C_final_ver.c
 Author      : syth0le
 Version     : 2.0
 Copyright   : my and only my
 Description : Calc on C. This calc can make different operations.
 There are multiplication'*', division'/', addition'+', subtraction'-', exponentiation'^', factorial'!'.
 In this program realized function of cooperation with users.
 You can continue using calc or exit him, when request will be appeared.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float firstNum, secondNum, var1, var2, result;  // main working vars
    int choose;  // var for choosing operation type
    int ist1;  // var for cycle 'for'
    int turn_on = 1; // var of 1-'on' or 0-'off' program
    char sign = '$';
    int size; // var for using size of memory in vector operations
    float *vector1, *vector2;
    while(turn_on != 0){
        printf("Choose calc mode:");
        printf("1 - num. operations, 2 - vector operations");
        scanf(" %i", &choose);
        if (choose == 1){
            printf("type first number:"); // typing first number
            scanf("%f%*c", &firstNum);
            while(sign == '$'){
                printf("type sign from range('+', '-', '*', '/', '^', '!'): ");
                scanf("%c%*c", &sign); // typing sign of the operation
                if (sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '^'){
                    printf("type second number:"); // typing second number
                    scanf("%f%*c", &secondNum);
                    switch (sign) {
                        case '+': // typing '+' for addition
                            printf("%.2f\n", firstNum+secondNum);
                            break;
                        case '-': // typing '-' for subtraction
                            printf("%.2f\n", firstNum-secondNum);
                            break;
                        case '*': // typing '*' for multiplication
                            printf("%.2f\n", firstNum*secondNum);
                            break;
                        case '/': // typing '/' for division
                            if (secondNum != 0) printf("%.2f\n", firstNum/secondNum);
                            else printf("mistake!U can't divide into 0\n");
                            break; // if u divide into 0 there is error message will be appeared
                        case '^': // typing '^' for exponentiation
                            var2 = 1;
                            var1 = 1;
                            for (int ist1=1;ist1<=secondNum;ist1++){
                                var1 = var2;
                                var2 = var1 * firstNum;}
                            printf("%.2f\n", var2);
                            break;}
                }
                else if(sign == '!'){ // typing '!' for factorial
                    var1=0;
                    var2=1;
                    for (int ist1=1; ist1<=firstNum;ist1++){
                        var2 = var2 * ist1;
                        var1 = var2;}
                    printf("%.2f\n", var2);}
                else {
                    printf("unsupportable sign. \nPlease, type another from this range: +, -, *, /, ^, !.\n");
                    sign = '$';
                }
            }
        }
        else if (choose == 2){
            printf("Type vector's size: ");
            scanf("%d", &size);
            vector1 = calloc(size,sizeof(float));
            for (int i = 0; i < size; i++) {
                printf("Enter cords first vector (a): ");
                scanf("%f", &vector1[i]);
            }
//there must be cycle while for sign proverki( work with sign var like in num operations
            while(sign == '$'){
                printf("type sign from range: \n");
                printf("'+'-vectors addition, \n");
                printf("'-'-vectors subtraction \n");
                printf("'*'- scalar product of vectors \n");
                scanf("%c%*c", &sign);
                if (sign == '+' || sign == '-' || sign == '*'){
                    vector2 = calloc(size,sizeof(float));
                    for (int i = 0; i < size; i++) {
                        printf("Enter cords second vector (b): "); // rewrite all printfs and delete all otstupi
                        scanf("%f", &vector2[i]);
                    }
                    switch (sign) {
                        case '+':
                            printf("\n Result: ("); // thinking about different types result output in console
                            for (int i = 0; i < size; i++){
                                printf("%.2f", vector1[i] + vector2[i]);
                                if (i != size-1) printf(" ");
                            }
                            printf(")\n\n");

                            break;
                        case '-':
                            printf("\n Result: ("); // thinking about different types result output in console
                            for (int i = 0; i < size; i++){
                                printf("%.2f", vector1[i] + vector2[i]);
                                if (i != size-1) printf(" ");
                            }
                            printf(")\n\n");
                            break;
                        case '*':
                            for (int i = 0; i < size; i++) {
                            result += vector1[i] * vector2[i];
                            }
                            printf("\n Result: %.2f\n\n", result);
                            break;
                    }
                }
                else{
                    printf("unsupportable sign. \nPlease, type another from this range: +, -, *, /, ^, !.\n");
                    printf("'+'-vectors addition, \n");
                    printf("'-'-vectors subtraction \n");
                    printf("'*'- scalar product of vectors \n");
                    sign = '$';
                }
            }
        }
        else{
            printf("Unsupportable mode type.\nChoose from this list:");
            printf("1 - num. operations, 2 - vector operations");
        }



        printf("If u want to continue type 1, but if u want to exit type 0:");
        scanf("%i", &turn_on);
    }
}
