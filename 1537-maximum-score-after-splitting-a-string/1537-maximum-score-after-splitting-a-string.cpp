class Solution {
public:
    int maxScore(string s) {
        int ans = 0, currscore = count(s.begin(),s.end(),'1');
        if(currscore==0){
            return s.length()-1;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                currscore++;
            }else{
                currscore--;
            }
            ans = max(currscore,ans);
        }
        return ans;
    }
};