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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int x = it.second.first, y = it.second.second;
            nodes[x][y].insert(node->val);

            if(node->left != nullptr) q.push({node->left, {x-1, y+1}});

            if(node->right != nullptr) q.push({node->right, {x+1, y+1}});

        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto it : p.second){
                col.insert(col.end(), it.second.begin(), it.second.end());
            }
            ans.push_back(col);
            
        }
        return ans;
    }
};