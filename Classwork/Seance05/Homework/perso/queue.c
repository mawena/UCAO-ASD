Queue *initQueue(int number){
    Queue *Queue = malloc(sizeof(*Queue));
    Item *item = malloc(sizeof(*item));

    if (Queue == NULL || person == NULL)
    {
        return 0;
    }

    item->number = number;
    item->next = NULL;
    
    Queue->first = item;

    return Queue;
}

void putOn(Queue *Queue, int number){
    Item *item = malloc(sizeof(*item));
    if(Queue == NULL || item == NULL){
        return;
    }else{
        item->number = number;
        item->next = NULL;
        if(Queue->first == NULL){
            Queue->first = number;
        }else{
            
        }
    }
}