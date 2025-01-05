class Solution {
public:
    bool isP(string s){
        if(s.length()==1){
            return true;
        }
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void solve(int ind,string& s,vector<string>& v,vector<vector<string>>& ans){
        if(ind==s.length()){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.length();i++){
            string word = s.substr(ind,i-ind+1);
            if(isP(word)){
                v.push_back(word);
                solve(i+1,s,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        solve(0,s,v,ans);
        return ans;
    }
};