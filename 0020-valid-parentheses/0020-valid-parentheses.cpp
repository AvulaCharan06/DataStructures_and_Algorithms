class Solution {
public:
    bool isValid(string s) {
       map<char, char>mpp;
       mpp[')'] = '(';
       mpp['}'] = '{';
       mpp[']'] = '[';

       int n = s.size();
       vector<char>st(n);
        int j = -1;
       for(auto i : s){
          if(i == '(' || i == '{' || i == '['){
            j++;
            st[j] = i;
          }else{
            if(j == -1) return false;
             if(st[j] == mpp[i]) j--;
             else return false;
          }
       }
       if(j == -1) return true;
       else return false;
    }
};