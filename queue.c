#include <stdio.h>
#include "graph.h"
#include "nodes.h"
#include <stdlib.h>
#include "queue.h"

/// @brief - Removing the node with the highest priority from the queue.
/// @param Pqueue - The queue we use.
/// @return - Returning the node we have removed from the queue.
pnode pop(ppq* Pqueue){
    ppq popped = *Pqueue;
    pnode node = (*Pqueue)->node;
    (*Pqueue) = (*Pqueue)->next;
    free(popped);
    return node;
}

/// @brief - Add a new ppq with ppq->node = "node".
/// @param Pqueue - Pointer to the queue.
/// @param node - The node we want to ada to ppq and then add him to the queue(linkedlist of ppq).
/// @param p - The priority.
void push(ppq* Pqueue, pnode node, int priority){
    ppq head_of_q = (*Pqueue);
    ppq new_node = (priority_queue*)malloc(sizeof(priority_queue));
    new_node->node = node;
    new_node->priority = priority;
    new_node->next = NULL;
    if (*Pqueue==NULL){//if the queue(linkedlist of ppq) is empty the new ppq will be the head of priorityqueue
        (*Pqueue) = new_node;
        return;
    }
    if ((*Pqueue)->priority < priority) {//If there are already ppq in the linkedlist of ppq and the new node's priority is higher
        new_node->next = *Pqueue;//then he will set him to be the head of the queue(linkedlist of ppq).
        (*Pqueue) = new_node;
    }
    else {//else we will add him when we will see the first ppq in the queue(linkedlist of ppq) that his priority is smaller.

        while (head_of_q->next != NULL){

            if(head_of_q->next->priority < priority){break;}

            head_of_q = head_of_q->next;

        }

        new_node->next = head_of_q->next;
        head_of_q->next = new_node;
    }
}