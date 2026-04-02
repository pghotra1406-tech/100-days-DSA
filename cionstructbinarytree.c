#include <stdlib.h>

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* buildHelper(int inorder[], int postorder[],
                             int inStart, int inEnd, int* postIndex) {
    
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // Build right first
    root->right = buildHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = buildHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {
    
    int postIndex = postorderSize - 1;
    return buildHelper(inorder, postorder, 0, inorderSize - 1, &postIndex);
}
