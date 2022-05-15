#define LIN 2
#define COL 2
#define COTE 3
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k;
    int *** tab = (int ***) malloc(LIN*sizeof(int**));
    for(i=0; i < LIN; i++){
        tab[i] = (int**) malloc(COL*sizeof(int*));
        for(j=0; j<COL; j++){
            tab[i][j] = (int *) malloc(COTE*sizeof(int));
            for(k = 0; k < COTE; k++){
                printf("tab[%d][%d][%d]=", i, j, k);
                scanf("%d", (*(*(tab+i)+j)+k));
            }
            free(tab[i][j]);
        }
        free(tab[i]);
    }
    free(tab);
    return 0;
}