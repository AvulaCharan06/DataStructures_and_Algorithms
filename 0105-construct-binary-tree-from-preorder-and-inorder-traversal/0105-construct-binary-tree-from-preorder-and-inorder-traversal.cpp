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
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preEnd, 
                         vector<int>& inorder, int instart, int inEnd){
        if(prestart > preEnd || instart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inRoot = mpp[root->val];
        int numsLeft = inRoot - instart;

        root->left = buildTree(preorder, prestart+1, prestart+numsLeft,
                                inorder, instart, inRoot-1 );
        root->right = buildTree(preorder, prestart+numsLeft+1, preEnd,
                                inorder, inRoot+1, inEnd );
       return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
       
        for(int i=0; i<n; i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, 
                                    inorder, 0, n-1);
         return root;                           
    }
   
};