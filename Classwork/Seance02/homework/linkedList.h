#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct{
    int mm;
    int dd;
    int yyyy;
}Date;

typedef struct
{
    char lastName[20];
    char firstName[60];
    Date birthDate;
}Person;

typedef struct Item Item;
struct Item{
    Person person;
    Item *next;
};

typedef struct List List;
struct List{
    Item *first;
};

Date initDate();
Person initPerson(Date *date);
void displayList(List *list);
void updateFirstItem(List *list, Person *person);
void deleteFirstItem(List *list);
List *initList(Person *person);
void insertItem(List *list, Person *person);

#endif // LINKEDLIST_H_INCLUDED