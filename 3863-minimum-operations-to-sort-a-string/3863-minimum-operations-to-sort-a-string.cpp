class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool sorted = true;
        char minch = 'z', maxch = 'a';
        for(int i=0;i<n;i++){
            minch = min(s[i],minch);
            maxch = max(s[i],maxch);
            if(i-1>=0){
                if(s[i]<s[i-1]){
                    sorted = false;
                }
            }
        }
        if(n==1 || sorted)  return 0;
        if(n==2 && !sorted) return -1;
        
        if(s[0]==minch || s[n-1]==maxch)  return 1;
        for(int i=1;i<n-1;i++){
            if(s[i]==minch || s[i]==maxch)  return 2;
        }
        return 3;
    }
};