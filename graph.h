#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int new_numbering;
} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_code(int* Vertexs, int index0, int size_of_arr, int size_of_nodes, int* ans, pnode head);
void TSP_cmd(pnode head);
void dijkstra_algo(int *arr,pnode from);
void change_order(int* j, int* index0);

#endif