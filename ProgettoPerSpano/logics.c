#include<logics.h>
#include<game_management.h>

Point initialize_point(int x, int y) // restituisce unm point in base alle coordinate
{
    Point result;
    result.x = x;
    result.y = y;
    return result;
}

initialize_field(char** Table1) // Inizializzo il campo di gioco
{
    int row, col;
    for(row = 0; row < ROWS; ++row){
        for(col = 0; col < COLS; ++col){
            Table1[row][col] = (col == COLS - 1 ) ? 0 : ' '; // nell'output lo 0 non si vede
        }
    }
}

int is_valid_entry(unsigned int entry, Shape new_tetramino) //??
{ 
    return entry + new_tetramino.col < 15;
}

void translate_rows(char** Table1, unsigned int entry) //sovrascrivo la riga interessata(parto da quella da sotto) con quella sopra
{
    int row, col;
    for(row = entry; row >= 0; --row){
        for(col = 0; col < COLS; ++col){
            Table1[row][col] = row ? Table1[row - 1][col] : ' ';  //Per evitare il Segmentation Fault della riga 0 (quella in alto)    
            Table1[row][col] = (col == COLS - 1 ) ? 0 : ' ';
        }
    }    
}

void check_row(char** Table1) //Controlla se cancella la linea una volta che si fa punto
{    
    int row, col;
    for(row = ROWS - 1; row >= 0; --row){
        int flag = 1; //controlla se la riga è vuota (1 è piena)
        for(col = 0; flag && col < COLS; ++col){
            flag = flag && Table1[row][col] == '*';
        }
        if(flag)
            translate_rows(Table1, row);//traslare verso il basso le altre righe
    }
}

int insert_tetramino(char** Table1, Shape new_tetramino, Point entry) // check per capire se posso far spawnare il tetramino e che mi scorre il table per farlo cadere fino alla posizione COLS
{                                                                    // Poi altra funzione per capire se il tetramino ha toccato il limite e quindi GAME OVER
    int row, col, flag = 1;
    for (row = 0; flag && entry.x + row < ROWS && row < new_tetramino.row; row++)
    {
        for (col = 0; flag && entry.y + col < COLS && col < new_tetramino.col; col++)
        {
            flag = flag && Table1[row + entry.x][col + entry.y] != '*' && Table1[row + entry.x][col + entry.y] != 0;
        }
    }

    if(flag){
        for (row = 0; entry.x + row < ROWS && row < new_tetramino.row; row++)
        {
            for (col = 0; entry.y + col < COLS && col < new_tetramino.col; col++)
            {
                Table1[row + entry.x][col + entry.y] = new_tetramino.array[row][col];
            }
        }
    }
    
    return flag;
}

int delete_tetramino(char** Table1, Shape tetramino, Point entry){ // cancello la posizione che aveva prima il tetramino
    int row, col, flag = 1;

    for (row = 0; flag && entry.x + row < ROWS && row < tetramino.row; row++)
    {
        for (col = 0; flag && entry.y + col < COLS && col < tetramino.col; col++)
        {
            flag = flag && Table1[row + entry.x][col + entry.y] == tetramino.array[row][col];
        }
    }

    if(flag){
        for (row = 0; entry.x + row < ROWS && row < tetramino.row; row++)
        {
            for (col = 0; entry.y + col < COLS && col < tetramino.col; col++)
            {
                Table1[row + entry.x][col + entry.y] = ' ';
            }
        }
    }
    
    return flag;
}

Shape rotate_tetramino(Shape Tetramino) //ruota tetramino
{

}


int is_game_over(char** Table1, Stack** tetramini)
{
    int i;
    for(i = 0; i < COLS - 1; ++i)//Non sia raggiunta la riga più alta
    {
        if(Table1[0][i] != ' ')
            return 1;
    }
    if(!(*tetramini))//Stack non sia vuoto
        return 2;

    return 0;
}

/*
TODO: Rotate tetramino
*/