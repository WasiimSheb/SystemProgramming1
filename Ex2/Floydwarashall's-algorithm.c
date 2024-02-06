#include <stdio.h>
#define INF 999
#define V 10

int min(int a, int b){
    return (a > b) ? b : a;
}

void exch(int graph[V][V], int distances[V][V]){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            distances[i][j] = graph[i][j];
        }
    }
}

void initvalues(int graph[V][V]){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            scanf("%d", &graph[i][j]);
        }
    }
}

void shortestpath(int adjacencymatrix[V][V]){
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = adjacencymatrix[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int thereisapath(int adjacencymatrix[V][V], int src, int dest){
    int dist[V][V];
    exch(adjacencymatrix, dist);
    shortestpath(adjacencymatrix);
    return (adjacencymatrix[src][dest] != INF) ? 1 : 0;
}
