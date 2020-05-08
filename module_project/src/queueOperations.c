#include <stdio.h>
#include "queueOperations.h"


//announce work indicators
queue *head_q = NULL;
queue *tail = NULL;

// function of putting string to queue from input file.
int putElement(FILE *input){
    queue *tmp = malloc(1 * sizeof(queue));
    fgets(tmp->string, sizeof(tmp->string), input);
    tmp->next = NULL;
    if(tail != NULL){
        tail->next = tmp;
        tail = tmp;
    } else{
        head_q = tmp;
        tail = tmp;
    }
    return 1;
}

// function of getting string from queue for the following work operations.
char *getElement(void){
    if(head_q != NULL) {
        char *data;
        data = head_q->string;
        head_q = head_q->next;
        return data;
    } else{return NULL;}
}


