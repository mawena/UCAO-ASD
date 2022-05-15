#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *initQueue(int value) {
  Item *item = malloc(sizeof(*item));
  Queue *queue = malloc(sizeof(*queue));

  if (item == NULL || queue == NULL) {
    return 0;
  } else {
    item->value = value;
    item->next = NULL;

    queue->first = item;
    return queue;
  }
}

void displayQueue(Queue *queue) {
  if (queue == NULL) {
    return;
  } else {
    Item *current = queue->first;
    while (current != NULL) {
      printf("value: %d", current->value);
      current = current->next;
    }
  }
}

void insertValue(Queue *queue, int value) {
  if (queue == NULL) {
    return;
  } else {
    Item *current = queue->first;
    while (current->next != NULL) {
      current = current->next;
    }

    Item *newItem = malloc(sizeof(*newItem));
    newItem->value = value;

    current->next = newItem;
  }
}

int scroll(Queue *queue) {
  if (queue == NULL) {
    return 0;
  } else {
    Item *first = queue->first;
    queue->first = first->next;
    int value = first->value;
    free(first);
    return value;
  }
}

void deleteFirstValue(Queue *queue) {
  if (queue == NULL) {
    return;
  } else {
    Item *first = queue->first;
    queue->first = first->next;
    free(first);
  }
}