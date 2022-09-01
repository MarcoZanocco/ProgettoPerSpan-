#define ROWS 10
#define COLS 15+1

#include <stdlib.h>
#include <graphics.h>
#include <game_management.h>

void print_field(char** Table1){
    cls(); /*Clearscreen*/
    int row, col;
    for(col = 0; col < COLS; ++col)
        printf("_");
    printf("\n");
    for(row = 0; row < ROWS; ++row)
        printf("|%s|\n", Table1[row]); //nella riga 24 di logics sostituisce lo 0 con la |
    printf("\n");
    for(col = 0; col < COLS; ++col)
        printf("_");
}

int print_menu(){
    int mode = 0;

    printf("######## ######## ######## ########  ####  ######\n  ##    ##          ##    ##     ##  ##  ##    ## \n ##    ##          ##    ##     ##  ##  ##       \n ##    ######      ##    ########   ##   ######  \n ##    ##          ##    ##   ##    ##        ## \n ##    ##          ##    ##    ##   ##  ##    ## \n    ##    ########    ##    ##     ## ####  ######  ");
    //sistemare scritta Tetris
    
    printf("Inserisci modelità di gioco:\n\t1 - Single Player\n\t2 - Multi Player\n");
    while(!mode){
        scanf("%d",mode);
        if(mode != 1 || mode != 2)
            printf("Reinserire la modalità di gioco, mona!");
    }
}

void print_stack(Stack** s)
{
    Stack *current = *s;
    while(current){
        char output;
        switch(current->data.class)
        {
            case I: output = 'I';
            break;
            case J: output = 'J';
            break;
            case L: output = 'L';
            break;
            case O: output = 'O';
            break;
            case S: output = 'S';
            break;
            case T: output = 'T';
            break;
            case Z: output = 'Z';
            break;
            default: output = ' ';
        }
        print("[%c] -> ", output);
        current = current->next;
    }
        
}