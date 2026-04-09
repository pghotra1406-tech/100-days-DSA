#include <stdlib.h>


int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}


struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    if (start == end)
        return root;

    int index = findIndex(inorder, start, end, rootVal);

    root->left = buildTreeHelper(preorder, inorder, start, index - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, index + 1, end, preIndex);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1, &preIndex);
}
