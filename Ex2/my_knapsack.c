#define W 20
#define V 5
#include <stdio.h>
int max(int a, int b){
    return (a > b)? a : b;
}

int knapsack(int weights[], int values[], int selectedbool[5]){
    int knap[V + 1][W + 1];
    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= W; j++) {
             if( i == 0 || j == 0){
                 knap[i][j] = 0;
             }
             else if(j >= weights[i - 1]){
                 knap[i][j] = max(knap[i - 1][j], knap[i - 1][j - weights[i - 1]] + values[i - 1]);
             }
             else{
                 knap[i][j] = knap[i - 1][j];
                 }
        }
    }
    int j = W;
    for (int i = V; i > 0 ; i--) {
        if(knap[i][j] != knap[i - 1][j]){
            selectedbool[i - 1] = 1;
            j -= weights[i - 1];
        }
    }
    return knap[V][W];
}

int main(){
    int value[V];
    int weight[V];
    int selected[5];
    char items[V];
    char result[V];
    for (int i = 0; i < 5; ++i) {
        scanf("%s", &items[i]);
        scanf("%d", &value[i]);
        scanf("%d", &weight[i]);
    }
    int sum = knapsack(weight, value, selected);
    int c = 0;
    printf("maximum profit: \n");
    printf("%d\n", sum);
    for (int i = 0; i < V; ++i) {
        if (selected[i] == 1) {
            result[c] = items[i];
            c++;
        }
    }
    printf("selected items: \n");
    for (int i = 0; i < V; ++i) {
        printf("%c", result[i]);
    }
    return 0;
}
