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

