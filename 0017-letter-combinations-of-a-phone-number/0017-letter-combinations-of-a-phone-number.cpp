class Solution {
public:
    void solve(int ind,string digits,unordered_map<char,string>&map,string w,vector<string>&ans){
        if(w.length()==digits.length()){
            if(w.length()>0)
                ans.push_back(w);
            return;
        }
        string s = map[digits[ind]];
        for(int i=0;i<s.length();i++){
            w+=s[i];
            solve(ind+1,digits,map,w,ans);
            w.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,string> m;
        m['2'] = "abc", m['3'] = "def", m['4'] = "ghi", m['5'] = "jkl", m['6'] = "mno", m['7'] = "pqrs", m['8'] = "tuv", m['9'] = "wxyz";
        solve(0,digits,m,"",ans);
        return ans;
    }
};