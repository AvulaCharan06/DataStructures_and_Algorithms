class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     // Using BFS TC = N * word.size() * 26 * log(n)
     //  TC = N * word.size() * 26 * 1; '1' if we use unordered_set
     // N = while loop, word.size()*26 = inner loop to find word, log(n) for set 
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
           string word = q.front().first;
           int steps = q.front().second;
           q.pop();
           if(word == endWord) return steps;
            
            for(int i=0; i<word.size(); i++){
                char original = word[i];
              for(char ch = 'a'; ch <= 'z'; ch++){
                   word[i] = ch; 
                 if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps+1});
                 }                 
              }
               word[i] = original;
            }
        }
        return 0;
    }
};