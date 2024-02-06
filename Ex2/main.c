#include <stdio.h>
#include"algorithms.h"
#define INF 99999
#define V 10

int graph[V][V];

int main() {
    char c;
    int i, j;
    while (scanf(" %c", &c) && c != 'D') {
        switch (c) {
            case 'A':
                initvalues(graph);
                break;
            case 'B':
                scanf("%d %d", &i, &j);
                printf("Path exists from vertex %d to vertex %d: %s\n", i, j, thereisapath(graph, i, j) ? "Yes" : "No");
                break;
            case 'C':
                scanf("%d %d", &i, &j);
                shortestpath(graph);
                printf("The shortest path from vertex %d to vertex %d is: %d\n", i, j, graph[i][j]);
                break;
            default:
                printf("Invalid option: %c\n", c);
                break;
        }
    }
    return 0;
}
