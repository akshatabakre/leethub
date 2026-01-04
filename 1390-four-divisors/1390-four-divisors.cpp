class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i:nums){
            int cnt = 0, sum = 0;
            if(i==1){
                continue;
            }
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    cnt++;
                    sum+=j;
                    if(j!=(i/j)){
                        cnt++;
                        sum+=(i/j);
                    }
                }
            }
            if(cnt==2){
                ans += (sum+1+i);
            }
        }
        return ans;
    }
};