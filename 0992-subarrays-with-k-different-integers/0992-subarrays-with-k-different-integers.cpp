class Solution {
public:
    int NumofSubarrays(vector<int>& nums, int k){
        int n=nums.size();
        int left =0, right=0, count=0;
        map<int, int> mpp;
        while(right < n){
            mpp[nums[right]]++;
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) mpp.erase(nums[left]);
                left++;
            }
            count += right-left+1;
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return NumofSubarrays(nums, k) - NumofSubarrays(nums, k-1); 
    }
};