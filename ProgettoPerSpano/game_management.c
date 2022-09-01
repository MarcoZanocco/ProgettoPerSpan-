#include <game_management.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

Stack* initialize_stack()
{
    Stack *new_stack = (Stack *) malloc(sizeof(Stack));
    if(!new_stack)
        return 0;
    return new_stack;
}

void destroy_stack(Stack* s)
{
    if(s->next)
        destroy_stack(s->next);
    free(s);
}

int push(Stack** s, Shape tetramino) //aggiunge in testa il tetramino
{
    Stack *new_cell = (Stack *) malloc(sizeof(Stack));
    if(!new_cell)
        return 0;
    new_cell->data = tetramino;
    new_cell->next = *s;
    *s = new_cell;
    return 1;
}

Shape pop(Stack **s)
{
    Stack *head = *s; // salvo il valore del puntatore della prima cella in modo che facendo ->next ed eliminandola, non ci siano problemi
    *s = (*s)->next;
    Shape result = head->data; //salvo il tetramino
    free(head);
    return result;
}

Stack* fill_stack(int count) //Creates a Stack of "count" random Shapes
{
    Stack *s; 
    srand(time(NULL));   // Initialization, should only be called once.
    int i;
    for(i = 0; i < count; ++i)
    {
        int r = rand() % count;      // Returns a pseudo-random integer between 0 and RAND_MAX.
    
        if(!push(s, Tetramini[r]))
            return 0;
    }
    return s;
}

int read_directions() //legge se si deve muovere a destra o a sinistra, sistemare
{
    int direction;
 /*   int flags = fcntl(0, F_GETFL, 0);

    if (flags == -1) {
        // fcntl unsupported
        perror("fcntl");
    }

    // set stdin to non-blocking
    flags |= O_NONBLOCK;
    if(fcntl(0, F_SETFL, flags) == -1) {
        // fcntl unsupported
        perror("fcntl");
    }

    char st[10] = {0}; // initialize the first character in the buffer, this is generally good practice
    printf ("Please enter a line of text : ");
    time_t end = time(0) + 5; //5 seconds time limit.

    // while
    while(time(0) < end  // not timed out
        && scanf("%s", st) < 1 // not read a word
        && errno == EAGAIN); // no error, but would block*/

    char* st = " ";

    scanf("%s",st);

    switch(st[0]) 
    {
        case 'D':
            direction = 1;
            break;
        case 'A':
            direction = -1;
            break;
        default:
            direction = 0;
    }

    return direction;
}
