#include "stdlib.h"
#include "stdio.h"
#include "graph.h"
#include "nodes.h"

/// @brief - deleting all the edges that goes into a node and freeing their spaces in the memory.
/// @param temp - The node we want to delete it's edges.
void delete_all_edges(pnode temp){
    pedge runner = temp->edges; //running on all of the edegs.
    while(runner!=NULL){
        pedge delete = runner;//in order to delete an edge without interupting the run on the edegs we need to keep the edge and then skip forward.
        runner = runner->next;
        free(delete);
    }
}

/// @brief - the function will delete an edge from "Node" to the vertex with value = node_num and will free the edge's space
/// in the memory.
/// @param value - the value of the node we want to delete.
/// @param Node - usually will be the the head of Vertex list in order to go through all of the list.
void delete_edge(int value, pnode Node){
    if(Node->edges!= NULL){//checking the head of the list.
        pedge N_e = Node->edges;
        while(N_e->next != NULL){//runnig on the list.
            if (N_e->next->endpoint->node_num == value){//checking if that node has an edge that go to the node with value = node_num.
                pedge remove = N_e->next;
                N_e->next = remove->next;
                free(remove);
                return;
            }
            N_e = N_e->next;
        }
    }
}

/// @brief - numbering all the vertexes in the linkedlist.
/// @param head - The head of the vertex list.
/// @return - returning the amount of vertex in the linkedlist.
int numbering (pnode head){
    int i=0;
    pnode runner = head;
    while (runner!=NULL){
        runner->new_numbering = i;
        i++;
        runner= runner->next;
    }
    return i;
}