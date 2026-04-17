struct Node* dfs(struct Node* node, struct Node** visited) {
    if (!node) return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i], visited);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* node) {
    if (!node) return NULL;

    struct Node* visited[101];
    for (int i = 0; i < 101; i++)
        visited[i] = NULL;

    return dfs(node, visited);
}
