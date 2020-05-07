#include "countOperations.h"

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

        default:
            return 0;
    }
}

float factorial(float number){
    float rez;
    int var1 = 1;
    for(int i = 1; i<=number; i++)
    {var1 = var1 * i;}
    rez = var1;
    return rez;
}

float vectors(int size, char sign, float *vector1, float *vector2){
    float result;
    float *result_u;

    switch (sign) {

       case '+':
           for (int i = 0; i < size; i++){
               result_u[i] = vector1[i] + vector2[i];}
           return result_u;

       case '-':
           for (int i = 0; i < size; i++){
               result_u[i] = vector1[i] + vector2[i];}
           return result_u;

       case '*':
           for (int i = 0; i < size; i++) {
               result += vector1[i] * vector2[i];}
           return result;

       default:
           return 0;
   }
}

