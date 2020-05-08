#ifndef QUEUEOPERATIONS_H_
#define QUEUEOPERATIONS_H_

/*
 There are functions which working with queue.
 1 - putElement function: put string which was read from input file.
 2 - getElement function: get string from queue.
*/


// announce work structure (queue for saving strings from the input file).
typedef struct command_list{
    char string[30];
    struct command_list *next;
}queue;

int putElement(FILE *input);
char *getElement(void);

#endif /* QUEUEOPERATIONS_H_ */
