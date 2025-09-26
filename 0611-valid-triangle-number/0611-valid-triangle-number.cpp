class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        if(n<3) return 0;
        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                int ind = upper_bound(nums.begin(),nums.begin()+j,nums[i]-nums[j]) - nums.begin();
                // cout<<j<<" "<<ind<<endl;
                cnt += (j - ind);
            }
        }
        return cnt;
    }
};