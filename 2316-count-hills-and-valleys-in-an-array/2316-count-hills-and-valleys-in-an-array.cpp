class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i){
                if(nums[i]!=v.back()){
                    v.push_back(nums[i]);
                }
            }else{
                v.push_back(nums[i]);
            }
        }
        int ans = 0;
        for(int i=1;i<v.size()-1;i++){
            if((v[i]<v[i-1] && v[i]<v[i+1])||(v[i]>v[i-1] && v[i]>v[i+1])){
                ans++;
            }
        }
        return ans;
    }
};