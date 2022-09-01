#define ROWS 10
#define COLS 15+1 /*Per carattere termine stringa*/

typedef enum{I,J,L,O,S,T,Z} tetramino_type;

//Per le regole, moduli del gioco
typedef struct {
    char **array;
    int row, col;
    tetramino_type class;
} Shape; //per tetramino

typedef struct{
    int x;
    int y;
} Point; //coppia di due interi che rappresenta un punto con coordinate x e y

/**
* 
*/
Point initialize_point(int x, int y);

/**
* 
*/
initialize_field(char** Table1);

/**
* 
*/
int is_valid_entry(unsigned int entry, Shape new_tetramino);

/**
* 
*/
void translate_rows(char** Table1, unsigned int entry);

/**
*
*/
int insert_tetramino(char** Table1, Shape new_tetramino, Point entry);

/**
*
*/
int delete_tetramino(char** Table1, Shape Tetramino, Point entry);

/**
*
*/
Shape rotate_tetramino(Shape Tetramino);

/**
*
*/
int is_game_over(char** Table1, Stack* tetramini);