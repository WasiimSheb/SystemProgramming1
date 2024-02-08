#include <stdio.h>
#include"my_mat.h"
#define INF 99999
#define V 10
#include "stdbool.h"

int main() {
    char c;
    int i, j;

    int graph[V][V];
    while (scanf(" %c", &c) && c != 'D') {
        switch (c) {
            case 'A':
                initvalues(graph);
                break;
            case 'B':
                scanf("%d %d", &i, &j);
                bool a = thereisapath(graph, i, j);
                if(i == j){ printf("False\n");}
                else {printf("%s \n", a? "True" : "False");}
                break;
            case 'C':
                scanf("%d %d", &i, &j);
                int ans = shortestpath(graph, i, j);
                printf("%d\n",ans);
                break;
            default:
                printf("Invalid option: %c\n", c);
                break;
        }
    }
    return 0;
}
