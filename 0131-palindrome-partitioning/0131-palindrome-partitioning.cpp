class Solution {
public:
    bool isPalindrome(string s){
        if(s.length()==1){
            return true;
        }else{
            int n = s.length();
            for(int i=0;i<n/2;i++){
                if(s[i]!=s[n-i-1]){
                    return false;
                }
            }
            return true;
        }
    }
    void solve(string s,int ind,vector<string>&v,vector<vector<string>>&ans){
        if(ind==s.length()){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.length();i++){
            string word = s.substr(ind,i-ind+1);
            if(isPalindrome(word)){
                // cout<<word<<endl;
                v.push_back(word);
                solve(s,i+1,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(s,0,v,ans);
        return ans;
    }
};