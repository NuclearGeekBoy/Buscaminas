#include "backend.h"

void print_clear(char clear,char size_mat,char mat[8][8])
{
    char cont_x,cont_y;
    
    if(clear)
    {
        for(cont_y = 0 ; cont_y < size_mat ; cont_y++){
            for(cont_x = 0 ; cont_x < size_mat ; cont_x++){
                mat[cont_x][cont_y] = 0;
            }
        }
    }

    for(cont_y = 0 ; cont_y < size_mat ; cont_y++){
        for(cont_x = 0 ; cont_x < size_mat ; cont_x++)
        {
            printf("| %d ",mat[cont_x][cont_y]);
            if(cont_x == size_mat -1)
            {
                printf("|\n");
            }
        }
    }
}
