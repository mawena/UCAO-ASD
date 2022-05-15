#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct{
    int dd;
    int mm;
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

List *initList(Person *person);
void displayList(List *list);
void insertItem(List *list, Person *person);
void updateFirstItem(List *list, Person *person);
void deleteFirstItem(List *list);
List *copyList(List *list);
List *reverseCopyList(List *list);

#endif // LINKEDLIST_H_INCLUDED