#define N 3
#include <stdio.h>

int main(){
    int i;
    int tab[N];
    printf("Saisie des valeurs\n");
    for(i=0; i<N; i++){
        printf("tab[%d]=", i);
        scanf("%d", &tab[i]);
    }

    printf("\nAffichage des valeurs des valeurs\n");
    for(i=0; i<N; i++){
        printf("tab[%d]=%d\n", i, tab[i]);
    }
    return 0;
}