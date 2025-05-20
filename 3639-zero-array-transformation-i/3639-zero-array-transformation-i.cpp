class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> v(n,0);
        for(int i=0;i<m;i++){
            v[queries[i][0]]++;
            if(queries[i][1]+1<n){
                v[queries[i][1]+1]--;
            }
        }
        // cout<<v[0]<<" ";
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
            // cout<<v[i]<<" ";
        }
        for(int i=0;i<n;i++){
            if(nums[i]>v[i]){
                return false;
            }
        }
        return true;
    }
};