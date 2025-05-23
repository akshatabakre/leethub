class Solution {
    map<string,int> mpp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word,vector<string>& seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mpp[word];
        for(int i=0;i<word.length();i++){
            char og = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = og;
        }
    }
public:
    vector<vector<string>> findLadders(string bw, string e, vector<string>& wL) {
        set<string> st(wL.begin(),wL.end());
        queue<string> q;
        b = bw;
        q.push(b);
        st.erase(b);
        mpp[b] = 1;
        int size = b.length();
        while(!q.empty()){
            string word = q.front();
            q.pop();
            int steps = mpp[word];
            if(word==e){
                break;
            }
            for(int i=0;i<size;i++){
                char og = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps+1;
                    }
                }
                word[i] = og;
            }
        }
        if(mpp.find(e)!=mpp.end()){//if e not present, empty ans returned
            vector<string> seq;
            seq.push_back(e);
            dfs(e,seq);
        }
        return ans;
    }
};