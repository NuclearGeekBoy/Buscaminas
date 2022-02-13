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
    uint16_t length; //mat size
    uint16_t width;
    uint8_t bombs; //initial bomb amount
}game_invar;

//functs
void print_clear(char,char,tile_t mat[size_mat][size_mat]);
void init_mat(tile_t [size_mat][size_mat]);


int main()
{
    tile_t mat[size_mat][size_mat];
    init_mat(mat);
    print_clear(1,size_mat,mat);

}

void init_mat(tile_t mat[size_mat][size_mat])
{
    int cont_x, cont_y;
    for(cont_y = 0 ; cont_y < size_mat ; cont_y++){
            for(cont_x = 0 ; cont_x < size_mat ; cont_x++){
                mat[cont_x][cont_y].off_vision = 0;
            }
        }
}


void print_clear(char clear,char size_mat,tile_t mat[size_mat][size_mat])
{
    char cont_x,cont_y;
    
    if(clear)
    {
        for(cont_y = 0 ; cont_y < size_mat ; cont_y++){
            for(cont_x = 0 ; cont_x < size_mat ; cont_x++){
                mat[cont_x][cont_y].in_vision = 0;
            }
        }
    }

    for(cont_y = 0 ; cont_y < size_mat ; cont_y++){
        for(cont_x = 0 ; cont_x < size_mat ; cont_x++){
            printf("| %d ",mat[cont_x][cont_y].off_vision);
            if(cont_x == size_mat -1)
            {
                printf("|\n");
            }
        }
    }
}
