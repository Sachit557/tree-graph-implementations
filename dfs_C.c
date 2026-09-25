#include <stdio.h>
#include <stdlib.h>

void push_back(int **graph , const int x , const int y , int *size , int *cap); // inspired from c++ std::vector
void dfs(int vertex , int **graph , int *size , int *vis); // standard recursive dfs implementation

int main(void)
{
    printf("Enter number of nodes and number of edges\n");
    int n , m;
    scanf("%d %d" , &n , &m);

    int **graph = (int **)calloc( n+1 , sizeof(int *)); // actual adjacency list
    int *size = (int *)calloc(n+1 , sizeof(int)); // size of each list
    int *cap = (int *)calloc(n+1 , sizeof(int)); // capacity of each list
    int *vis = (int *)calloc(n+1 , sizeof(int)); // visited array to check if array has been visited before or not
    
    int x , y;
    // building the graph
    for (int i = 0 ; i < m ; ++i){
        scanf("%d %d" , &x , &y);
        push_back(graph ,x ,y , size , cap);   // bi directional
        push_back(graph ,y ,x , size , cap);
    }
    
    printf("\nAdjacency List : \n\n");
    for (int i = 1 ; i < n+1 ; ++i){
        printf("%d : " , i);
        for (int j = 0 ;j < size[i] ; ++j){
            printf(" %d " , graph[i][j]);
        }
        printf("\n");
    }
    
    printf("\nRecursive Depth first search\n");
    dfs(1 ,graph ,size , vis);    
   
    // free
    for (int i = 0 ; i < n+1 ; ++i)
        free(graph[i]);
    
    free(graph);
    free(size);
    free(cap);
    free(vis);

    return 0;
}

void push_back(int **graph , const int x , const int y , int *size , int *cap){
    if (cap[x] >= size[x]){
        if (cap[x])
            cap[x]*= 2;
        else
            cap[x] = 1;

       graph[x] = realloc(graph[x] , cap[x]*sizeof(int));
    }

    graph[x][size[x]++] = y;
}

void dfs(int vertex , int **graph , int *size , int *vis){
    vis[vertex] = 1;
    printf("%d  " , vertex);
    for (int i = 0 ; i < size[vertex] ; ++i){
         if (!vis[graph[vertex][i]])
             dfs(graph[vertex][i] , graph , size , vis);
     }
}
