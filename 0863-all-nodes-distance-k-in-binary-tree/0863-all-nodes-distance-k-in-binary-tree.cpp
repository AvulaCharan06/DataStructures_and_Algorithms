/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left != nullptr) {
            parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right != nullptr) {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    markParents(root, parent);  // Mark the parent of each node
    
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> que;
    que.push(target);
    visited[target] = true;
    
    int dis = 0;  // Distance variable to keep track of the current level
    while (!que.empty()) {
        int siz = que.size();
        // If we have processed `k` levels, break the loop
        if (dis == k) break;

        // Process all nodes at the current level
        for (int i = 0; i < siz; i++) {
            TreeNode* current = que.front();
            que.pop();

            // Process the left child
            if (current->left && !visited[current->left]) {
                visited[current->left] = true;
                que.push(current->left);
            }
            // Process the right child
            if (current->right && !visited[current->right]) {
                visited[current->right] = true;
                que.push(current->right);
            }
            // Process the parent node
            if (parent[current] && !visited[parent[current]]) {
                visited[parent[current]] = true;
                que.push(parent[current]);
            }
        }
        dis++;  // Increment the distance after processing one level
    }

    // Collect the result from the queue
    vector<int> ans;
    while (!que.empty()) {
        TreeNode* node = que.front();
        que.pop();
        ans.push_back(node->val);
    }
    return ans;
}
};