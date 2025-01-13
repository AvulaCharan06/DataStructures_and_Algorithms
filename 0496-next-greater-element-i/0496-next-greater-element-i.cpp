class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n);
        stack<int> st;
        unordered_map<int, int>mpp;
        for(int i =0; i<nums2.size(); i++){
            while(!st.empty() && nums2[i] > st.top()){
                mpp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            mpp[st.top()] = -1;
            st.pop();
        }
        for(int i=0; i<n; i++){
            ans[i] = mpp[nums1[i]];
        }
        return ans;

    }
};