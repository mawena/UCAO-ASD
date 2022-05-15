#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct Item Item;
struct Item{
    int number;
    Item *next;
};

typedef struct Queue Queue;
struct Queue{
    Item *first;
};

List *initList(int number);


#endif //QUEUE_H_INCLUDED