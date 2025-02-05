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
     unordered_map<int, int>mpp;
   TreeNode* buildTree(vector<int>& inorder, int instart, int inEnd, 
        vector<int>& postorder, int poststart, int postIndex){
        if(poststart > postIndex || instart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex]);
        
        int inRoot = mpp[root->val]; 
        int numsLeft = inRoot - instart;

        root->left = buildTree(inorder, instart, inRoot-1,
                                postorder, poststart, poststart+numsLeft-1);
        root->right = buildTree(inorder, inRoot+1, inEnd,
                                postorder, poststart+numsLeft, postIndex-1);
       return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        int postIndex = postorder.size()-1;
       TreeNode* root = buildTree(inorder, 0, inorder.size()-1, 
                                  postorder, 0, postorder.size()-1);
        
        return root;
    }
};