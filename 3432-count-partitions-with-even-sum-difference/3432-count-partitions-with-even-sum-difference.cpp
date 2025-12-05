class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int s = 0;
        for(int i:nums){
            s+=i;
        }
        int ps = 0;
        int ans = -1;
        for(int i:nums){
            ps+=i;
            if(abs(s-2*ps)%2==0){
                ans++;
            }
        }
        return max(0,ans);
    }
};