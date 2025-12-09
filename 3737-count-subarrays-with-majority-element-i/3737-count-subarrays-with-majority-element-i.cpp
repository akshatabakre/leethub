class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> f;
            // f[nums[i]]++;
            for(int j=i;j<n;j++){
                f[nums[j]]++;
                if(f[target]>(j-i+1)/2){
                    ans++;
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
        return ans;
    }
};