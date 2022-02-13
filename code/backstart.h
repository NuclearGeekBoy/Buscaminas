#ifndef BACKSTART
#define BACKSTART

/*STANDARD LIBRARIES*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdint.h>

/*BASIC DEFINITIONS*/
#define BEGINNER 9 //modes for the game
#define INTERMEDIATE 16
#define EXPERT 31 //its width
#define BMINE 10 //amount of mines for Beginner mode
#define IMINE 40
#define EMINE 99

/*here you can find some basic definitions of what the numbers mean inside the matrix, in vision and off vision*/
#define EMPTY 0
/*from 1 to 8, means the amount of bombs nearby*/
#define BOMB 9
#define UNDISCOVERED 10 //every game you start with every tile undiscovered
#define FLAG 11  //players shall put flags or question marks on the undiscovered tiles
#define QMARK 12 

/*STRUCTS FOR PUBLIC USE*/
typedef struct 
{
    uint16_t tiles; //when it reaches 0, the game is over. You discovered every tile bombless
    uint8_t bombs; //bomb counter to show during game
    time_t time; // 0s to 999s
}game_var; //game variables, every game may be different

typedef struct
{
    uint16_t length; //mat size
    uint16_t width;
    uint8_t bombs; //initial bomb amount
}game_invar; //game constants, invariables,

typedef struct
{
    uint8_t in_vision :4;
    uint8_t off_vision :4;
}tile_t;

/*FUNCTS*/
void print_clear(char,char,tile_t mat[BEGINNER][BEGINNER]); //

#endif
