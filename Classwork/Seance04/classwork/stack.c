
void toStack(Stack *stack, int v){
    Item *new = (element *)malloc(sizeof(element *));
    if(stack == NULL || new == NULL){
        return;
    }else{
        new->val = v;
        new->next = stack->first;

        stack->first = new;
    }
} 

int toUnStack(Stack *stack){
    Item *current =  stack->first;
    if(stack == NULL || current == NULL){
        return 0;
    }else{
        int v = current->val;
        stack->first = current->next;
        free(current);
        return v;
    }
}