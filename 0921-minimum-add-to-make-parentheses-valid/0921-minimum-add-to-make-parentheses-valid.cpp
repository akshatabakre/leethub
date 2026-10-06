class Solution {
public:
    int minAddToMakeValid(string s) {
        int ind = s.find('(');
        if(ind==string::npos){
            return s.length();
        }
        int ans = 0;
        if(ind>0){
            ans+=ind;
        }
        int p = 0;
        for(int i=ind;i<s.length();i++){
            if(s[i]=='('){
                p++;
            }else{
                p--;
            }
            if(p<0){
                ans++;
                p++;
            }
        }
        if(p>0){
            ans+=p;
        }
        return ans;
    }
};