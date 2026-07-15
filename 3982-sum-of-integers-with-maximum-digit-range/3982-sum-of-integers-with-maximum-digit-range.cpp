class Solution {
public:
    int dr(int x){
        set<int> dig;
        while(x){
            int r = x%10;
            dig.insert(r);
            x/=10;
        }
        return (*dig.rbegin() - *dig.begin());
    }
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int maxdr = 0;
        for(int i=0;i<n;i++){
            maxdr = max(dr(nums[i]),maxdr);
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            if(dr(nums[i])==maxdr){
                sum+=nums[i];
            }
        }
        return sum;
    }
};