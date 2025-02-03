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
   int balancedTree(TreeNode* node){
    //Base case
     if(node == nullptr) return 0;

    //Recursive case
     int lheight = balancedTree(node->left);
     if(lheight == -1) return -1;
     int rheight = balancedTree(node->right);
     if(rheight == -1) return -1;

     if(abs(lheight - rheight) > 1) return -1;
     return max(lheight, rheight) + 1;

   }
    bool isBalanced(TreeNode* root) {
        return balancedTree(root) != -1; 
    }
};