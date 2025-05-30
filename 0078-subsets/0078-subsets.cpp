class Solution {
public:
  void subsetSum(int ind, vector<int>&nums, vector<int>&ds, vector<vector<int>>& ans, int n){
     //Base Case 
     if(ind >= n){
        ans.push_back(ds);
        return;
     }

     //pick up the element
      ds.push_back(nums[ind]);
      subsetSum(ind+1, nums, ds, ans, n);
      ds.pop_back();

     // Not pick up the element
     subsetSum(ind+1, nums, ds, ans, n);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> ds;
       int n = nums.size();
    //    int sum=0;
       subsetSum(0, nums, ds, ans, n);
    //    sort(ans.begin(), ans.end());

       return ans; 
    }
};