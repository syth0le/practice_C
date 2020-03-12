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
    float firstNum, secondNum, var1, var2;  // main working vars
    int ist0;  // var for cycle 'for'
    int ist1;  // var for cycle 'for'
    int turn_on = 1; // var of 1-'on' or 0-'off' program
    char sign = '+';
    while(turn_on != 0){ //
        printf("type first number:"); // typing first number
        scanf("%f%*c", &firstNum);
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
        else printf("unsupportable sign. Please, type another from this range: +, -, *, /, ^, !.\n");
        printf("If u want to continue type 1, but if u want to exit type 0:");
        scanf("%i", &turn_on);
    }

}
