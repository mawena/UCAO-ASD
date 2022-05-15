#define N 10
#include <stdio.h>
int main(){
    int i, val;
    int *tab = (int *) malloc( N * sizeof(int));
    printf("Saisie des valeurs\n");
    for(i=0; i < N; i++){
        printf("tab[%d]=", i);
        scanf("%d", (tab+i));
    }

    printf("\nAffichage des valeurs des valeurs\n");
    for(i=0; i<N; i++){
        printf("tab[%d]=%d\n", i, tab[i]);
    }
}