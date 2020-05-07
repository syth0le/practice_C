#include <stdio.h>
#include "queueOperations.h"

queue *head_q = NULL;
queue *tail = NULL;

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


char *getElement(void){
    if(head_q != NULL) {
        char *data;
        data = head_q->string;
        head_q = head_q->next;
        return data;
    } else{return NULL;}
}


