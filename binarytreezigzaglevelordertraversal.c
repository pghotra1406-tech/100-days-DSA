#include <stdlib.h>

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 1000;

    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 0;

    while (front < rear) {

        int size = rear - front;

        int* temp = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            
            int index = (level % 2 == 0) ? i : (size - 1 - i);
            temp[index] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        result[level] = temp;
        (*returnColumnSizes)[level] = size;

        level++;
    }

    *returnSize = level;
    return result;
}
