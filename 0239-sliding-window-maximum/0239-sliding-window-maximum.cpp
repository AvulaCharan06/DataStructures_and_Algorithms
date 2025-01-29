class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int> dq;
        for(int i=0; i<n; i++){
         // removing elements from the front of deque if it exceeds the k   
            if(!dq.empty() && dq.front() <= i-k) dq.pop_front();
         // removing smaller elements from back of deque
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
         // push index of the elements   
            dq.push_back(i);
// add larger element to the ans, obviously the element which is at front is the largest element of that size k 
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
      // Tc - O(2n) ; Sc - O(n-k) + O(k);
    // O(n) for iteration and other O(n) for push & pop operations, overall it takes n;


    }
};