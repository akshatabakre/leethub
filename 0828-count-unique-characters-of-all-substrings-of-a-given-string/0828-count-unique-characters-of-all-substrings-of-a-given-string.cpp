class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();
        vector<int> nexts(26,n), nextocc(n,n);
        for(int i=n-1;i>=0;i--){
            nextocc[i] = nexts[s[i]-'A'];
            nexts[s[i]-'A'] = i;
        }
        // for(int i:nextocc)  cout<<i<<" ";
        int ans = 0;
        vector<int> prevocc(26,-1);
        for(int i=0;i<n;i++){
            ans += (i-prevocc[s[i]-'A'])*(nextocc[i]-i);
            prevocc[s[i]-'A'] = i;
        }
        return ans;
    }
};