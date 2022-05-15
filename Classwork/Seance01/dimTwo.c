#define N 2
#define M 3
#include <stdio.h>

int main(){
    int i, j;
    int tab[N][M];
    printf("Saisie des valeurs\n");
    for(j=0; i<N; j++){
        for(j=0; i<M; i++){
            printf("tab[%d][%d]=", i, j);
            scanf("%d", &tab[i][j]);
        }
        printf("\n");
    }

    printf("\nAffichage des valeurs des valeurs\n");
    for(i=0; i<N; i++){
        for(j=0; i<M; j++){
            printf("tab[%d][%d]=%d\n", i, j, tab[i][j]);
        }
        printf("\n");
    }
    return 0;
}