class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        while(!q.empty()){
            int t = q.front().first;
            string s = q.front().second;
            q.pop();
            if(s==endWord){
                return t;
            }
            for(int i=0;i<s.length();i++){
                char og = s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i] = ch;
                    if(st.count(s)){
                        q.push({t+1,s});
                        st.erase(s);
                    }
                }
                s[i] = og;
            }
        }
        return 0;
    }
};