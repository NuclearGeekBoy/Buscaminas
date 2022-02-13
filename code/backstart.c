#include "backend.h"

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
        for(cont_x = 0 ; cont_x < size_mat ; cont_x++)
        {
            printf("| %d ",mat[cont_x][cont_y].in_vision);
            if(cont_x == size_mat -1)
            {
                printf("|\n");
            }
        }
    }
}
