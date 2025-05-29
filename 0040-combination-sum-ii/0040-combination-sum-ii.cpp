class Solution {
public:
   void findCombination(int ind, int target, vector<int>& candidates, vector<int>& ds,
    vector<vector<int>>& ans){
       //Base Case
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        // Recursive case
        for(int i= ind; i<candidates.size(); i++){
           if(i>ind && candidates[i] == candidates[i-1]) continue;
           if(candidates[i] > target) break;
           ds.push_back(candidates[i]);
           findCombination(i + 1, target-candidates[i], candidates, ds, ans);
           ds.pop_back(); // while backtracking remove current element

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findCombination(0, target, candidates, ds, ans);

        return ans;
    }
};