class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && k>0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
     // Remove remaining k digits from the top of the stack
        while(k>0){           // Tc - O(3n) + O(k); Sc - O(n) + O(n);
            st.pop();
            k--;
        }
       // create a new string  
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        while(ans.size() != 0 && ans.back() == '0'){
            ans.pop_back();
        }
      // reverse the string to get correct order
        reverse(ans.begin(), ans.end());       
         
        if(ans.size() == 0) return "0";
        return ans;
    }
};