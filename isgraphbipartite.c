#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

int isBipartite(int** graph, int graphSize, int* graphColSize) {
    
    int color[MAXN];
    
    
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    int queue[MAXN];
    

    for (int i = 0; i < graphSize; i++) {
        
        if (color[i] != -1)
            continue;

        
        int front = 0, rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int j = 0; j < graphColSize[node]; j++) {
                int neighbor = graph[node][j];

                
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                
                else if (color[neighbor] == color[node]) {
                    return 0; 
                }
            }
        }
    }

    return 1; 
}
