class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int sq = i*i + j*j;
                int rt = sqrt(sq);
                if(rt*rt==sq && rt<=n){
                    ans++;
                    if(i!=j){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};