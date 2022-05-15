#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(){

    Date birthDate = initDate();
    printf("Données de l'utilisateur1:\n");
    Person person = initPerson(&birthDate);
    List *list = initList(&person);
    printf("\nDonnées de l'utilisateur2:\n");
    Person person2 = initPerson(&birthDate);
    insertItem(list, &person2);
    
    // printf("\n");
    // printf("Affichage:==================================================================================");
    // displayList(list);
    // printf("============================================================================================\n\n");
    
    // updateFirstItem(list, &person);
    // printf("Affichage après la modification:============================================================");
    // displayList(list);
    // printf("============================================================================================\n\n");

    // deleteFirstItem(list);
    // printf("Affichage après la supression:==============================================================");
    // displayList(list);
    // printf("============================================================================================\n\n");

    return 0;
}
