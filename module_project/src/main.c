/*
 ============================================================================
 Name        : module_project.c
 Author      : sythole
 Version     :
 Copyright   : my and only my
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "countOperations.h"
#include "queueOperations.h"
#include "stackOperations.h"




int main(void) {
    float rez, fact, rez_vect;
    float *yvector1;
    float *yvector2;
    yvector1[0] = 1;
    yvector1[1] = 2;
    yvector1[2] = 3;
    yvector2[0] = 3;
    yvector2[1] = 3;
    yvector2[2] = 3;
    rez = numbers('-', 3, 5);
    fact = factorial(5);
    rez_vect = vectors(3, '*', yvector1, yvector2);
    printf("%f", rez_vect);
	printf("%f %f", rez, fact);
	return EXIT_SUCCESS;
}
