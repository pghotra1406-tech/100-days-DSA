#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node, time;
} Pair;


typedef struct {
    Pair arr[10000];
    int size;
} MinHeap;

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* h, int node, int time) {
    h->arr[h->size++] = (Pair){node, time};
    int i = h->size - 1;

    while(i > 0 && h->arr[i].time < h->arr[(i-1)/2].time) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

Pair pop(MinHeap* h) {
    Pair top = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while(1) {
        int left = 2*i+1, right = 2*i+2, smallest = i;

        if(left < h->size && h->arr[left].time < h->arr[smallest].time)
            smallest = left;
        if(right < h->size && h->arr[right].time < h->arr[smallest].time)
            smallest = right;

        if(smallest == i) break;

        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }

    return top;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {


    int adj[n+1][n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            adj[i][j] = -1;

    for(int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj[u][v] = w;
    }

    
    int dist[n+1];
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;

    
    MinHeap heap;
    heap.size = 0;

    push(&heap, k, 0);

    while(heap.size > 0) {
        Pair curr = pop(&heap);

        int node = curr.node;
        int time = curr.time;

        for(int i = 1; i <= n; i++) {
            if(adj[node][i] != -1) {
                int newTime = time + adj[node][i];

                if(newTime < dist[i]) {
                    dist[i] = newTime;
                    push(&heap, i, newTime);
                }
            }
        }
    }

    
    int maxTime = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX)
            return -1;
        if(dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}
