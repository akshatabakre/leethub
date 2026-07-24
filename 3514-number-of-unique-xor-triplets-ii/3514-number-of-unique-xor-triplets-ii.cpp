class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s.insert(nums[i]^nums[j]);
            }
        }

        unordered_set<int> ans;
        for(int i=0;i<n;i++){
            for(int x:s){
                ans.insert(x^nums[i]);
            }
        }
        return ans.size();
    }
};