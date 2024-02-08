#include <stdio.h>
#include <limits.h>
#include "stdbool.h"
#define INF Int_max
#define V 10

int shortestpath(int matrix[V][V], int src, int dest);
void initvalues(int graph[V][V]){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
}

bool thereisapath(int matrix[V][V], int source, int dest){
    int ans = shortestpath(matrix, source, dest);
    if(ans > 0){return true;}
    return false;

}

int shortestpath(int matrix[V][V], int src, int dest){
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = matrix[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if(dist[i][k] != 0 && dist[k][j] != 0 && (dist[i][j] == 0 || dist[i][j] > dist[i][k] + dist[k][j])){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    if(src == dest){return  -1;}
    if(dist[src][dest] == 0) {
        return  -1;
    }
    else {
        return dist[src][dest];
    }
}
