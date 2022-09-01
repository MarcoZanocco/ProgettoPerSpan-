#include <stdio.h>
#include <logics.h>
#include <graphics.h>
#include <game_management.h>

#define NUMERO_PEZZI 10

char Table1[ROWS][COLS] = {0};

typedef enum tetratype{S,Z,T,L,ML,SQ,R} TetraType;

typedef struct { //fare in base alla shape da dove iniziare
    char **array;
    int row, col;
    TetraType type;
} Shape;

Shape current;
Stack *current_tetramini;

int game_mode = 0, iterations = 0;

int main(){
    int current_player = 0;
    game_mode = print_menu();
    current_tetramini = game_mode == 1 ? fill_stack(NUMERO_PEZZI) : fill_stack(2*NUMERO_PEZZI);
    initialize_field(Table1);
    do{            
        switch(game_mode){
            case 1: //single player
                int result, score = 0;
                while(!(result = is_game_over(Table1, current_tetramini)))
                {
                    print_field(Table1);
                    Shape current_tetramino = pop(&current_tetramini);
                    Point tetramino_position = initialize_point(5, 0);
                    int direction;
                    while(insert_tetramino(Table1, current_tetramino, tetramino_position)) //inseriamo tetramino
                    {
                        print_field(Table1);
                        clrscr();
                        printf("Inserisci la direzione: [0 -> SX ; 1 -> CX ; 2 -> DX]");
                      /*printf("Inserisci la direzione:[-1 -> SX ; 0 -> CX ; 1 -> DX]");*/
                        direction = read_directions();
                        delete_tetramino(Table1, current_tetramino, tetramino_position);
                        tetramino_position.y += 1;
                        tetramino_position.x += direction - 1;
                        score += check_row(Table1);
                    } 
                    ++iterations;
                }

                switch(result){
                    case 1: 
                        printf("GAME OVER");
                        break;
                    case 2:
                        printf("YOU WON"); 
                        break;
                    default: printf("???");
                }
                break;
                
            case 2: //multiplayer
                int result1, result2, score2;
                int score1 = score2 = 0;
                char Table2[ROWS][COLS];
                initialize_field(Table2);

                while(!(result1 = is_game_over(Table1, current_tetramini)) || !(result2 = is_game_over(Table2, current_tetramini)))
                {
                    char** current_table = (!current_player) ? Table1:Table2; //cambia il tavolo dei giocatori
                    int* current_score = (!current_player) ? &score1:&score2;
                    print_field(current_table);
                    Shape current_tetramino = pop(&current_tetramini);
                    Point tetramino_position = initialize_point(5, 0);
                    int direction;
                    while(insert_tetramino(current_table, current_tetramino, tetramino_position)) //inseriamo tetramino
                    {
                        print_field(current_table);
                        printf("Inserisci la direzione: [0 -> SX ; 1 -> CX ; 2 -> DX]");
                      /*printf("Inserisci la direzione:[-1 -> SX ; 0 -> CX ; 1 -> DX]");*/
                        direction = read_directions();
                        delete_tetramino(current_table, current_tetramino, tetramino_position);
                        tetramino_position.y += 1;
                        tetramino_position.x += direction - 1;
                        *current_score += check_row(current_table);
                        clrscr();
                    } 
                    current_player = (current_player + 1) % 2;
                    ++iterations;
                }

                switch(result){
                    case 1: 
                        printf("GAME OVER");
                        break;
                    case 2:
                        printf("YOU WON"); 
                        break;
                    default: printf("???");
                }                
                break;
        }
    }while(game_mode != 0);
}

/*

| ***      |
|   *      |
|          |
|          |
|          |
|          |
|          |
|          |
|          |
|          | 
|          |
|          |
|*         |
|**********|
|__________|
*/

/*
TODO: Rotate tetramino (logics.c)

*/  

 /*
 nmake -f Makefile.win
 nmake
 */