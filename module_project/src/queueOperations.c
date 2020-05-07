#include <stdio.h>
#include "queueOperations.h"

typedef struct command_list{
    char string[30];
    struct command_list *next;
}queue;

queue *head = NULL;
queue *tail = NULL;

int putElement(FILE *input){
    queue *tmp = malloc(1 * sizeof(queue));
    fgets(tmp->string, sizeof(tmp->string), input);
    tmp->next = NULL;
    if(tail != NULL){
        tail->next = tmp;
        tail = tmp;
    } else{
        head = tmp;
        tail = tmp;
    }
    return 1;
}


char *getElement(void){
    if(head != NULL) {
        char *data;
        data = head->string;
        head = head->next;
        return data;
    } else{return NULL;}
}


