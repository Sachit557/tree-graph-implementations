/* 
 Adjacency matrix graph implementation
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

struct graph{
    int n;
    int matrix[MAX_SIZE][MAX_SIZE];
};

struct node{
    int data;
    struct node *next;
};

struct queue{
    struct node *rear;
    struct node *front;
};

// queue
void InitQueue(struct queue *ptr_queue);
void DeinitQueue(struct queue *ptr_queue);
int IsFullQueue(struct queue *ptr_queue);
int IsEmptyQueue(struct queue *ptr_queue);
void Enqueue(struct queue *ptr_queue , int key);
int Dequeue(struct queue *ptr_queue );

// graph
void InitGraph(struct graph *ptr_graph , int n);
void InsertGraph(struct graph *ptr_graph , int u , int v);
void PrintMatrix(struct graph *ptr_graph);
void DepthFirstSearch(struct graph *ptr_graph , int u);
void BreadthFirstSearch(struct graph *ptr_graph , int u);

// not called directly
void DepthFirstSearchRecursive(struct graph *ptr_graph ,int *used ,int u);
 
int main()
{
    int n , e , u , v;
    printf("Enter number of nodes and edges\n");
    scanf("%d %d" , &n , &e);
    
    if (n > MAX_SIZE){
        printf("Max size of graph is %d " , MAX_SIZE);
        return 1;
    }

    struct graph mygraph;
    InitGraph(&mygraph , n);

    for (int i = 0; i < e ; ++i){
        scanf("%d %d" , &u , &v);
        if (u < n && v < n)
            InsertGraph(&mygraph , u , v); 
        else{
            printf("Max size of graph is %d " , MAX_SIZE);
            return 1;
        }
    }

    PrintMatrix(&mygraph);
    printf("DFS : \n");
    DepthFirstSearch(&mygraph , 0); 
    printf("BFS : \n");
    BreadthFirstSearch(&mygraph , 0);

    return 0;
}


void InitGraph(struct graph *ptr_graph , int n){
    if (n > MAX_SIZE) return;
    
    ptr_graph->n = n;
    for (int i = 0 ; i < MAX_SIZE ; ++i)
        for (int j = 0; j < MAX_SIZE ; ++j)
            ptr_graph->matrix[i][j] = 0;
}

void InsertGraph(struct graph *ptr_graph , int u , int v){
    if (u >= ptr_graph->n || v >= ptr_graph->n) return;
    ptr_graph->matrix[u][v] = 1;
    ptr_graph->matrix[v][u] = 1;
    // undirected graph
} 

void PrintMatrix(struct graph *ptr_graph){
    for (int i = 0; i < ptr_graph->n; ++i){
        for (int j = 0; j < ptr_graph->n; ++j)
            printf("%d " , ptr_graph->matrix[i][j]);
        printf("\n");
    }
}

void DepthFirstSearch(struct graph *ptr_graph , int u){
    int used[ptr_graph->n] = {0};
    DepthFirstSearchRecursive(ptr_graph , used , u);
    printf("\n");
}

void DepthFirstSearchRecursive(struct graph *ptr_graph , int *used , int u){
    used[u] = 1;
    printf("%d " , u);
    for (int child = 0 ; child < ptr_graph->n ; ++child)
        if (ptr_graph->matrix[u][child] && !used[child] ){
            DepthFirstSearchRecursive(ptr_graph , used , child);
        }
}

void BreadthFirstSearch(struct graph *ptr_graph , int u){
    struct queue myqueue;
    InitQueue(&myqueue);

    int used[ptr_graph->n] = {0};
    used[u] = 1;
    Enqueue(&myqueue, u);

    while(!IsEmptyQueue(&myqueue)){
        u = Dequeue(&myqueue);
        printf("%d " , u);

        for (int child = 0 ; child < ptr_graph->n ; ++child)
            if (ptr_graph->matrix[u][child] && !used[child]){
                Enqueue(&myqueue , child);
                used[child] = 1;
            }
    }
    printf("\n");
}

void Enqueue(struct queue *ptr_queue , int key){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = NULL;
    if (IsEmptyQueue(ptr_queue)){
        ptr_queue->front = ptr_queue->rear = newnode;
    }
    else{
        ptr_queue->rear->next = newnode;
        ptr_queue->rear = newnode;
    }
}

int Dequeue(struct queue *ptr_queue ){
    if (IsEmptyQueue(ptr_queue)){
        printf("queue is empty\n");
        return -1;
    }
    else{
        int val = ptr_queue->front->data;
        struct node *temp = ptr_queue->front;
        ptr_queue->front = ptr_queue->front->next;
        if (ptr_queue->front == NULL) ptr_queue->rear = NULL;
        free(temp);
        return val;
    }
}

int IsFullQueue(struct queue *ptr_queue){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    free(temp);
    return temp == NULL;
}

int IsEmptyQueue(struct queue *ptr_queue){
    return ptr_queue->front == NULL;
}

void InitQueue(struct queue *ptr_queue){
    ptr_queue->front=ptr_queue->rear=NULL;
}

void DeinitQueue(struct queue *ptr_queue){
    while(!IsEmptyQueue(ptr_queue)){
        Dequeue(ptr_queue);
    }
}

