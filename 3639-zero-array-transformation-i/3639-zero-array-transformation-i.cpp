class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> v(n,0);
        int m = q.size();
        for(int i=0;i<m;i++){
            int l = q[i][0], r = q[i][1];
            v[l]--;
            if(r<n-1) v[r+1]++;
        }
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }
        bool f = true;
        for(int i=0;i<n;i++){
            if(v[i]>-(nums[i]))    f = false;
        }
        return f;
    }
};