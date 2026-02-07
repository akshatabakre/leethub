class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> A(n,0);
        A[0] = (s[0]=='a');
        for(int i=1;i<n;i++){
            A[i] = A[i-1] + int(s[i]=='a');
        }
        if(A[n-1]==0)   return 0;
        int ans = n;
        for(int i=0;i<n;i++){
            int x = (i-A[i]);
            x+=A[n-1];
            if(i){
                x-=A[i-1];
            }
            ans = min(x,ans);
        }
        return ans;
    }
};