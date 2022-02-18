//libraries
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BEGINNER 9
#include<stdint.h>

int size_mat = BEGINNER;

//estructuras
typedef struct
{
    uint8_t in_vision :2; //0 = undiscovered, 1 = flag, 2 = Question mark, 3 = discovered
    uint8_t off_vision :4; // 0 - 8 = the amount of bombs nearby, 10 = bomb
    uint8_t unused :2; //probably doing some weird shit in the future
}tile_t;

typedef struct
{
    uint16_t tiles; //Amount of tiles undiscovered. When it reaches 0, the game is over. You discovered every tile bombless
    int8_t bombs; //bomb counter to show during game. May show negative numbers
    time_t time; // 0s to 999s
}game_var;

typedef struct
{
    uint8_t first_x; //first tile clicked x and y starting from 0 on the left-up corner
    uint8_t first_y;
    uint16_t length; //mat size
    uint16_t width;
    uint8_t bombs; //initial bomb amount
}game_invar;

//functs
void init_mat(char size_y,char size_x,tile_t mat[size_y][size_x]);
void print_clear(char size_y,char size_x,tile_t mat[size_y][size_x]);
void set_mines(tile_t[game_invar.width][game_invar.length],game_invar*);

int main()
{
    srand(time(NULL));
    tile_t mat[size_mat][size_mat+size_mat];
    init_mat(size_mat,size_mat+size_mat,mat);
    print_clear(size_mat,size_mat+size_mat,mat);
    game_invar game;
}

void init_mat(char size_y,char size_x,tile_t mat[size_y][size_x])
{
    char cont_x, cont_y;
    for(cont_y = 0 ; cont_y < size_y ; cont_y++){
            for(cont_x = 0 ; cont_x < size_x ; cont_x++){
                mat[cont_y][cont_x].off_vision = 0;
                mat[cont_y][cont_x].in_vision = 0;
            }
        }
}

/*void set_mines(tile_t mat[game->width][game->length],game_invar *game)
{
    char cont_x,cont_y; 
    
    
     for(cont_y = 0 ; cont_y < game->width ; cont_y++){
            for(cont_x = 0 ; cont_x < game->length ; cont_x++){
                printf(".");
            }
        }
    
    
    
    
}*/
    
void print_clear(char size_y,char size_x,tile_t mat[size_y][size_x])
{
    char cont_y,cont_x;
    
    printf("off vision:\n");
    for(cont_y = 0 ; cont_y < size_y ; cont_y++){
        for(cont_x = 0 ; cont_x < size_x ; cont_x++){
            printf("| %d ",mat[cont_y][cont_x].off_vision);
            if(cont_x == size_x -1)
            {
                printf("|\n");
            }
        }
    }
    printf("\nin vision:\n");
    for(cont_y = 0 ; cont_y < size_y ; cont_y++){
        for(cont_x = 0 ; cont_x < size_x ; cont_x++){
            printf("| %d ",mat[cont_y][cont_x].in_vision);
            if(cont_x == size_x -1)
            {
                printf("|\n");
            }
        }
    }
}
