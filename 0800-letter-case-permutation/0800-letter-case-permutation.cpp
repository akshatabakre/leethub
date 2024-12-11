class Solution {
public:
    void solve(string&s,string word,int ind,vector<string>&ans){
        if(ind==s.length()){
            ans.push_back(word);
            return;
        }
        //add and skip the number
        if(s[ind]>='0' && s[ind]<='9'){
            word+=s[ind];
            solve(s,word,ind+1,ans);
            word.pop_back();
        }else{
            //alphabets
            //lowercase
            if(s[ind]>='a' && s[ind]<='z')
                word+=s[ind];
            else
                word+=(s[ind]-'A'+'a');
            solve(s,word,ind+1,ans);
            word.pop_back();
            //uppercase
            if(s[ind]>='A' && s[ind]<='Z')
                word+=s[ind];
            else
                word+=(s[ind]-'a'+'A');
            solve(s,word,ind+1,ans);
            word.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s,"",0,ans);
        return ans;
    }
};