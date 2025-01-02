class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        int len = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>v.back()){
                v.push_back(nums[i]);
                len++;
                // cout<<"pushing "<<nums[i]<<endl;
            }else{
                int ind = lower_bound(v.begin(),v.end(),nums[i]) - v.begin();
                v[ind] = nums[i];
            }
        }
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        return len;
    }
};