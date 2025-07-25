class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int,int> f;
        for(int i:nums){
            f[i]++;
        }
        int maxsum = 0;
        for(auto i:f){
            if(i.first>0){
                maxsum+=i.first;
            }
        }
        if(maxsum==0){
            maxsum = -1e9;
            for(auto i:f){
                maxsum = max(i.first,maxsum);
            }
        }
        return maxsum;
    }
};