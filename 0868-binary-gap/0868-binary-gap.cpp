class Solution {
public:
    int binaryGap(int n) {
        int i=0,prev=-1;
        int ans = 0;
        while(n){
            if(n%2){
                if(prev!=-1){
                    ans = max(i-prev,ans);
                }
                prev = i;
            }
            i++;
            n/=2;
        }
        return ans;
    }
};