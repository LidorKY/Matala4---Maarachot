typedef struct priority_queue {
    int priority;
    struct priority_queue* next;
    pnode node;
} priority_queue,*ppq;

pnode pop(ppq* Pqueue);
void push(ppq* Pqueue, pnode node, int priority);