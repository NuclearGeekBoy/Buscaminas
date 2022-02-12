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
void print_clear(char,char,char mat[BEGINNER][BEGINNER]); //

#endif
