#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


int main(){
    Date *birthDate = malloc(sizeof(*birthDate));
    birthDate->yyyy = 2000;
    birthDate->mm = 3;
    birthDate->dd = 3;

    Person *person = malloc(sizeof(*person));
    strcpy(person->lastName, "lastName1");
    strcpy(person->firstName, "firstName1");
    person->birthDate = *birthDate;

    Person *person2 = malloc(sizeof(*person2));
    strcpy(person2->lastName, "lastName2");
    strcpy(person2->firstName, "firstName2");
    person2->birthDate = *birthDate;

    Person *person3 = malloc(sizeof(*person3));
    strcpy(person3->lastName, "lastName3");
    strcpy(person3->firstName, "firstName3");
    person3->birthDate = *birthDate;


    List *list = initList(person);
    insertItem(list, person2);
    List *list2 = copyList(list);
    updateFirstItem(list2, person3);
    List *list3 = reverseCopyList(list2);

    printf("\n");
    printf("Affichage Liste1:===========================================================================");
    displayList(list);
    printf("============================================================================================\n\n");

    printf("\n");
    printf("Affichage Liste2:===========================================================================");
    displayList(list2);
    printf("============================================================================================\n\n");

    printf("\n");
    printf("Affichage Liste3:===========================================================================");
    displayList(list3);
    printf("============================================================================================\n\n");
    int n;

    return 0;
}