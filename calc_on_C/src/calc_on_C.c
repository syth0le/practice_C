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
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float firstNum, secondNum, var1, var2, result;  // main working vars
    int choose;  // var for choosing operation type
    int ist1;  // var for cycle 'for'
    char turn_on = 'l'; // var any button -'on' or q-'off' program
    char sign = '$', l;
    int size; // var for using size of memory in vector operations
    float *vector1, *vector2;

    printf("What do u want to use?\n Choose f - file, c - console.");
    printf("\nEnter your choice: ");
    scanf("%c%*c", &l);

    switch (l){
        case 'f':


        case 'c':
            while(turn_on != 'q'){
                sign = '$';
                printf("Choose calc mode: ");
                printf("1 - num. operations, 2 - vector operations: ");
                scanf(" %i", &choose);
                if (choose == 1){
                    printf("type first number: "); // typing first number
                    scanf(" %f%*c", &firstNum);
                    while(sign == '$'){
                        printf("type sign from range('+', '-', '*', '/', '^', '!'): ");
                        scanf("%c%*c", &sign); // typing sign of the operation
                        printf("type second number:"); // typing second number
                        switch (sign) {

                            case '+': // typing '+' for addition
                                scanf("%f%*c", &secondNum);
                                printf("%.2f\n", firstNum+secondNum);
                                break;

                            case '-': // typing '-' for subtraction
                                scanf("%f%*c", &secondNum);
                                printf("%.2f\n", firstNum-secondNum);
                                break;

                            case '*': // typing '*' for multiplication
                                scanf("%f%*c", &secondNum);
                                printf("%.2f\n", firstNum*secondNum);
                                break;

                            case '/': // typing '/' for division
                                scanf("%f%*c", &secondNum);
                                if (secondNum != 0) {
                                    printf("%.2f\n", firstNum/secondNum);}
                                else printf("mistake!U can't divide into 0\n");
                                break; // if u divide into 0 there is error message will be appeared

                            case '^': // typing '^' for exponentiation
                                scanf("%f%*c", &secondNum);
                                var2 = 1;
                                var1 = 1;
                                for (int ist1=1;ist1<=secondNum;ist1++){
                                    var1 = var2;
                                    var2 = var1 * firstNum;}
                                printf("%.2f\n", var2);
                                break;

                            case '!': // typing '!' for factorial
                                var1=0;
                                var2=1;
                                for (int ist1=1; ist1<=firstNum;ist1++){
                                    var2 = var2 * ist1;
                                    var1 = var2;}
                                printf("%.2f\n", var2);
                                break;

                            default:
                                printf("unsupportable sign.Please, type another from this range: +, -, *, /, ^, !.\n");
                                sign = '$';
                                break;
                        }
                    }
                }
                else if (choose == 2){             //choosing coordinate system
                    printf("You can choose coordinate system 2 - two-dimensional or 3 - three-dimensional\n");
                    printf("Type vector's size: ");
                    scanf("%i", &size);
                    vector1 = calloc(size,sizeof(float));
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
                        vector2 = calloc(size,sizeof(float));
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
                }
                else{
                    printf("Unsupportable mode type.\nChoose from this list:");
                    printf("1 - num. operations, 2 - vector operations");
                }
                sign = '$';
                printf("If u want to continue type any button,\n but if u want to exit from console mode type q:");
                scanf(" %c%*c", &turn_on);
        }
        free(vector1);
        free(vector2);
        break;

        default:
            printf("This unsupportable mode. Try again, follow descriptions.\n");
            break;
    }
}
