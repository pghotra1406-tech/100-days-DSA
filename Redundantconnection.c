#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001

int parent[MAXN];


int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}


void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb)
        parent[pa] = pb;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    
    
    for (int i = 1; i <= edgesSize; i++) {
        parent[i] = i;
    }

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        
        if (find(u) == find(v)) {
            result[0] = u;
            result[1] = v;
            *returnSize = 2;
            return result;
        }

        unionSet(u, v);
    }

    return NULL;
}
