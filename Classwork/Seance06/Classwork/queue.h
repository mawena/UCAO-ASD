#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct Item Item;
typedef struct Queue Queue;

struct Item {
  int value;
  Item *next;
};

struct Queue {
  Item *first;
};

Queue *initQueue(int value);
void displayQueue(Queue *queue);
void insertValue(Queue *queue, int value);
void updateFirstValue(Queue *queue, int newValue);
int scroll(Queue *queue);
void deleteFirstValue(Queue *queue);

#endif // QUEUE_H_INCLUDED