#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

Date initDate(){
    Date *date = malloc(sizeof(*date)); 
    printf("Entrez la date suivant le format yyyy/mm/dd:");
    scanf("%d/%d/%d", &date->yyyy, &date->mm, &date->dd);
    return *date;
}

Person initPerson(Date *date){
    Person *person = malloc(sizeof(*person));
    printf("Nom:");
    scanf("%s", person->lastName);
    printf("Prénoms:");
    scanf("%s", person->firstName);
    person->birthDate = *date;
    return *person;
}

List *initList(Person *person){
    Item *item = malloc(sizeof(*item));
    List *list = malloc(sizeof(*list));

    if (list == NULL || person == NULL)
    {
        return 0;
    }

    item->person = *person;
    item->next = NULL;
    
    list->first = item;

    return list;
}

void displayList(List *list){
    if(list == NULL){
        return;
    }else{
        Item *current = list->first;
        while(current != NULL){
            printf("\nNom: %s\nPrenom: %s\nDate de naissance: %d/%d/%d\n", current->person.lastName, current->person.firstName, current->person.birthDate.dd, current->person.birthDate.mm, current->person.birthDate.yyyy);
            current = current->next;
        }
    }
}

void insertItem(List *list, Person *person){
    Item *newItem = malloc(sizeof(*newItem));
    if(list == NULL || newItem == NULL){    //On vérifie si les variables ne sont pas vides en raison de manques de mémoire ou de mauvaise manipulation
        return;
    }else{
        newItem->person = *person;
        newItem->next = list->first;
        list->first = newItem;
    }
}

void updateFirstItem(List *list, Person *person){
    if(list == NULL){
        return;
    }else{
        Item *current = list->first;
        list->first->person = *person;
    }
}

void deleteFirstItem(List *list){
    if(list == NULL){
        return;
    }else{
        Item *current = list->first;
        list->first = list->first->next;
        free(current);
        if(list->first == NULL){
            free(list);
        }
    }
}

List *copyList(List *list){
    List *newList = malloc(sizeof(*newList));
    if(newList == NULL){
        return 0;
    }else{
        Item *current = list->first;
        Item *newCurrent = malloc(sizeof(*newCurrent));
        newCurrent->person = current->person;
        newCurrent->next = NULL;
        newList->first = newCurrent;
        if(list->first->next != NULL){
            current = list->first->next;
            while(current != NULL){
                Item *newItem = malloc(sizeof(*newItem));
                newItem->person  = current->person;
                newItem->next  = NULL;
                newCurrent->next = newItem;
                newCurrent = newItem;
                current = current->next;
            }
        }
    }
    return newList;
}

List *reverseCopyList(List *list){
    List *newList = malloc(sizeof(*newList));
    if(newList == NULL){
        return 0;
    }else{
        Item *current = list->first;
        Item *newCurrent = malloc(sizeof(*newCurrent));
        newCurrent->person = current->person;
        newCurrent->next = NULL;
        newList->first = newCurrent;
        if(list->first->next != NULL){
            current = list->first->next;
            while(current != NULL){
                Item *newItem = malloc(sizeof(*newItem));
                newItem->person = current->person;
                newItem->next  = newCurrent;
                newList->first = newItem;
                current = current->next;
                newCurrent = newItem;
            }
        }
    }
    return newList;
}