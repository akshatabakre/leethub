class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        #define int long long
        int n = nums.size();
        vector<int> suffmin(n);
        int mini = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffmin[i] = mini;
            mini = min((long long)nums[i],mini);
        }
        vector<int> prefsum(n);
        prefsum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefsum[i]=nums[i]+prefsum[i-1];
        }
        int maxscore = -1e18;
        for(int i=0;i<n-1;i++){
            maxscore = max(maxscore,prefsum[i]-suffmin[i]);
        }
        return maxscore;
        #undef int
    }
};