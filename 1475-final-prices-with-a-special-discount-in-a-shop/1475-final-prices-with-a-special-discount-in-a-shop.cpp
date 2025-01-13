class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        vector<int>ans = prices;
        for(int i=0; i<n; i++){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                // apply discount to previous item using current item
                ans[st.top()] -= prices[i];
                st.pop();   
            }
            
            // add current index to stack
            st.push(i);
        }
        return ans;
    }
};