class Solution {
public:
    bool ispalindrome(int n,int b){
        string s = "";
        while(n>0){
            s+=char(n%b + '0');
            n/=b;
        }
        bool p = true;
        for(int i=0;i<=s.length()/2;i++){
            if(s[i]!=s[s.length()-i-1]){
                p = false;
            }
        }
        return false;
    }
    bool isStrictlyPalindromic(int n) {
        bool ans = true;
        for(int i=2;i<=n-2;i++){
            if(!ispalindrome(n,i)){
                ans=false;
                break;
            }
        }
        return ans;
    }
};