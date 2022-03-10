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
    uint8_t off_vision :4; // 0 - 8 = the amount of bombs nearby, 9 = bomb
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
    uint16_t height; //mat size
    uint16_t width;
    uint8_t bombs; //initial bomb amount
}game_invar;

//functs
void init_mat(game_invar *game_data,tile_t *);
void print_clear(game_invar *game_data,tile_t*);
void set_mines(game_invar *game_data,tile_t *);

int main()
{
    srand(time(NULL));
    game_invar game;
    game.width = size_mat*2;
    game.height = size_mat;
    game.bombs = game.width*game.height/3;
    
    tile_t *mat = malloc(sizeof(tile_t)*game.width*game.height); //matriz
    
    tile_t *point;
    point = mat;
    
    init_mat(&game,point);
    
    set_mines(&game,point);
  
    print_clear(&game,point);
}

void init_mat(game_invar *game_data,tile_t *tile)
{
    char cont_x, cont_y;
    for(cont_y = 0 ; cont_y < game_data->height ; cont_y++){
        for(cont_x = 0 ; cont_x < game_data->width ; cont_x++)
            {
            tile->off_vision = 0;
            tile->in_vision = 0;
            tile++;
            }
    }
}

void set_mines(game_invar *game,tile_t *tile)
{
    char bomb_count = 0;
   // tile_t *aux = tile;
    char y_axis,x_axis;
   // printf("%d\n%d\n",bomb_count,game->bombs);
    for(bomb_count = 0 ; bomb_count < game->bombs ; bomb_count++)
    {
        y_axis = rand() % game->height;
        x_axis = rand() % game->width;
    //    printf("y_axis = %d\nx_axis = %d\n",y_axis,x_axis);
        tile[x_axis + y_axis*game->width].off_vision = 10;
    }
}
    
void print_clear(game_invar *game_data,tile_t *tile)
{
    char cont_y,cont_x;
    tile_t *aux;
    aux = tile; //aux pointer to storage the start of the mat
    
    printf("off vision:\n");
    for(cont_y = 0 ; cont_y < game_data->height ; cont_y++){
        for(cont_x = 0 ; cont_x < game_data->width ; cont_x++)
        {
            printf("| %d ",tile->off_vision);
            if(cont_x == game_data->width -1)
            {
                printf("|\n");
            }
            tile++;
        }
    }
    tile = aux; //now i use it in order to printf the 'in vision' mat
    
    printf("\nin vision:\n");
    for(cont_y = 0 ; cont_y < game_data->height ; cont_y++){
        for(cont_x = 0 ; cont_x < game_data->width ; cont_x++)
        {
            printf("| %d ",tile->in_vision);
            if(cont_x == game_data->width-1)
            {
                printf("|\n");
            }
            tile++;
        }
    }
}
