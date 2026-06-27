class Solution {
public:
    int characterReplacement(string s, int x) {
        int n=s.length();
        int ans=0;
        for(char ch='A' ; ch<='Z' ;ch++){
            int maxi=0;
            int l=0;
            int r=-1;
            int k=x;
            while(l<n){
                while(r+1<n && (s[r+1]==ch || k>0)){
                    r++;
                    if(s[r]!=ch){
                        k--;
                    }
                }
                maxi=max(maxi,r-l+1);
                if(r<l){
                    l++;
                    r=l-1;
                }
                else{
                    if(s[l]!=ch)k++;
                    l++;
                }
            }
         
            ans=max(ans,maxi);
        }
        return ans;
        
    }
};