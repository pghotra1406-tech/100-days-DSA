#include <stdio.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int queue[10000][2];
    int front = 0, rear = 0;
    int fresh = 0, minutes = 0;

    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    
    while (front < rear && fresh > 0) {
        int size = rear - front;
        minutes++;

        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];

                if (nx >= 0 && ny >= 0 && nx < gridSize && ny < gridColSize[0] && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;

                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                }
            }
        }
    }

    return (fresh == 0) ? minutes : -1;
}
