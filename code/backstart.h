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

typedef struct
{
    uint8_t in_vision :2; //0 = undiscovered, 1 = flag, 2 = Question mark, 3 = discovered
    uint8_t off_vision :4; // 0 to 8 = the amount of bombs nearby, 10 = bomb
    uint8_t unused :2; //probably doing some weird shit in the future
}tile_t;

/*here you can find some basic definitions, in vision and off vision meaning*/
#define BOMB 10
#define SAFE 0 //no bombs in the tile nor nearby

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

/*FUNCTS*/
void print_clear(char,char,tile_t mat[size_mat][size_mat]);
void init_mat(tile_t mat[size_mat][size_mat]);
/*
 - llenar el off vision
 - switchear in vision
 - game over 
 - rellenar estructuras
 - maquina de estado de menu
 - reesctructurar backend
 - aprender time.h
 -

*/
#endif
