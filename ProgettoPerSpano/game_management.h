#include<logics.h>

#define INPUT_LEN 10

struct stack{
    Shape data;
    struct stack *next;
}; 

const Shape Tetramini[7]= {
    {(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3},                           //Forma ad S     
    {(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3},                           //Forma ad Z     
    {(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //Forma ad t     
    {(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //Forma ad l     
    {(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //Forma ad j   
    {(char *[]){(char []){1,1},(char []){1,1}}, 2},                                                   //Forma ad o
    {(char *[]){(char []){0,0,0,0}, (char []){1,1,1,1}, (char []){0,0,0,0}, (char []){0,0,0,0}}, 4} //Forma ad i
};

typedef struct stack Stack;

void destroy_stack(Stack* s);

int push(Stack** s, Shape tetramino);

Shape pop(Stack **s);

Stack* fill_stack(int count);

int read_directions();
