class Solution {
public:
    bool possible(string w1,string w2){
        if(w1.length()!=w2.length()+1){
            return false;
        }
        int i=0,j=0;
        while(i<w1.length()){
            if(w1[i]==w2[j]){
                i++,j++;
            }else{
                i++;
            }
        }
        if(i==w1.length() && j==w2.length()){
            return true;
        }
        return false;
    }
    static bool comp(string& s1,string& s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size(),len = 1;
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(possible(words[i],words[j])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            len = max(len,dp[i]);
        }
        return len;
    }
};