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
void init_mat(game_invar game_data,tile_t *);
void print_clear(game_invar game_data,tile_t*);
//void set_mines(tile_t[game_invar.width][game_invar.length],game_invar*);

int main()
{
    srand(time(NULL));
    tile_t mat[size_mat][size_mat+size_mat]; //matriz
    game_invar game;
    game.width = size_mat;
    game.length = size_mat*2;
    
    tile_t *point;
    point = (tile_t*) &mat;
    
    init_mat(game,point);
    print_clear(game,point);
}

void init_mat(game_invar game_data,tile_t *tile)
{
    char cont_x, cont_y;
    for(cont_y = 0 ; cont_y < game_data.width ; cont_y++){
            for(cont_x = 0 ; cont_x < game_data.length ; cont_x++){
                tile->off_vision = 0;
                tile->in_vision = 0;
                tile++;
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
    
void print_clear(game_invar game_data,tile_t *tile)
{
    char cont_y,cont_x;
    tile_t *aux;
    aux = tile; //aux pointer to storage the start of the mat
    
    printf("off vision:\n");
    for(cont_y = 0 ; cont_y < game_data.width ; cont_y++){
        for(cont_x = 0 ; cont_x < game_data.length ; cont_x++){
            printf("| %d ",tile->off_vision);
            if(cont_x == game_data.length -1)
            {
                printf("|\n");
            }
            tile++;
        }
    }
    tile = aux; //now i use it in order to printf the 'in vision' mat
    
    printf("\nin vision:\n");
    for(cont_y = 0 ; cont_y < game_data.width ; cont_y++){
        for(cont_x = 0 ; cont_x < game_data.length ; cont_x++){
            printf("| %d ",tile->in_vision);
            if(cont_x == game_data.length-1)
            {
                printf("|\n");
            }
            tile++;
        }
    }
}
