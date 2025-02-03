/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int heightofTree(TreeNode* node, int& diameter){
      //Base Case
      if(node == nullptr) return 0;

      // Recursive Case
      int lh = heightofTree(node->left, diameter);
      int rh = heightofTree(node->right, diameter);
      diameter = max(diameter, lh+rh);

      return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        heightofTree(root, diameter);
        return diameter;
    }
};