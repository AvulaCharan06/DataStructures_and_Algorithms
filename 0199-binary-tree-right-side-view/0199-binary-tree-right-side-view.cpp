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
    void recursion(TreeNode* node, int level, vector<int>& ans){
      //Base case 
      if(node == nullptr) return;

      //Recursive case
      if(ans.size() == level) ans.push_back(node->val);
      recursion(node->right, level+1, ans);
      recursion(node->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursion(root, 0, ans);
        return ans;
     // we used reverse of preorder(root, left, right) and reverse preorder(root,right,left);
       //Tc - O(n) we traverse every node 
       //Sc - O(h) h = height of tree 
    }
};