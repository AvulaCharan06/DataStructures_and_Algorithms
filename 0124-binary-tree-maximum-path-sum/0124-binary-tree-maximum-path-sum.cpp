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
    int findmaxPath(TreeNode* node, int &maxi){
      //Base Case  
        if(node == NULL) return 0;

      //Recursive Case
       int leftsum = max(0, findmaxPath(node->left, maxi));
       int rightsum = max(0, findmaxPath(node->right, maxi));
       maxi = max(maxi, leftsum + rightsum + node->val);

       return max(leftsum, rightsum) + node->val;  
    }
    int maxPathSum(TreeNode* root) {
         int maxi = INT_MIN;
         findmaxPath(root, maxi);
         return maxi;
    }
};