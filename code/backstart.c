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
