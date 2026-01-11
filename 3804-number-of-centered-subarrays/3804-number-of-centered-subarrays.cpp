class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int len=1;len<=n;len++){
            unordered_map<int,int> f;
            int sum = 0;
            for(int i=0;i<len;i++){
                sum+=nums[i];
                f[nums[i]]++;
            }
            if(f[sum]>0){
                // cout<<0<<" "<<len<<endl;
                ans++;
            }
            for(int i=0;i+len<n;i++){
                sum-=nums[i];
                f[nums[i]]--;
                if(f[nums[i]]==0){
                    f.erase(nums[i]);
                }
                sum+=nums[i+len];
                f[nums[i+len]]++;
                if(f[sum]>0){
                // cout<<i+1<<" "<<len<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};