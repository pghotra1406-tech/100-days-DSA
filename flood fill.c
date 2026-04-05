#include <stdio.h>

void dfs(int** image, int m, int n, int r, int c, int origColor, int newColor) {
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (image[r][c] != origColor)
        return;

    image[r][c] = newColor;

    dfs(image, m, n, r + 1, c, origColor, newColor);
    dfs(image, m, n, r - 1, c, origColor, newColor);
    dfs(image, m, n, r, c + 1, origColor, newColor);
    dfs(image, m, n, r, c - 1, origColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes) {

    int origColor = image[sr][sc];

    if (origColor != color) {
        dfs(image, imageSize, imageColSize[0], sr, sc, origColor, color);
    }

    // Set return values
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}
