#ifndef QUEUEOPERATIONS_H_
#define QUEUEOPERATIONS_H_

typedef struct command_list{
    char string[30];
    struct command_list *next;
}queue;

int putElement(FILE *input);
char *getElement(void);

#endif /* QUEUEOPERATIONS_H_ */
