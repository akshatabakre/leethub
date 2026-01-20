class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int a=-1,b=-1,c=-1;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')   a=i;
            if(s[i]=='b')   b=i;
            if(s[i]=='c')   c=i;
            int mini = -1;
            if(a!=-1 && b!=-1 && c!=-1){
                mini = min(a,min(b,c));
            }
            ans += (mini+1);
        }
        return ans;
    }
};