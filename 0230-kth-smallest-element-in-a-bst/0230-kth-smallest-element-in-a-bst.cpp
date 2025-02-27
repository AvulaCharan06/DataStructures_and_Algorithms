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
    void findKthsmallest(TreeNode* root, int k, int &cnt, int &Ksmallest){

        if(!root || cnt >= k) return;
     // check on left subtree for kth smallest value
        findKthsmallest(root->left, k, cnt, Ksmallest);

        cnt++;
        if(cnt == k){
            Ksmallest = root->val;
            return;
        }
      
      // if smallest is not found on left sub tree 
      // go for right sub tree
      findKthsmallest(root->right, k, cnt, Ksmallest);

        
    }
    int kthSmallest(TreeNode* root, int k) {
        int Ksmallest = 0;
        int cnt = 0;

        findKthsmallest(root, k, cnt, Ksmallest);
        return Ksmallest;
    }
};