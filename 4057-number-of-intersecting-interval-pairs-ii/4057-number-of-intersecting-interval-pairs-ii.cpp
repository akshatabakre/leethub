class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        long long ans = 0;
        vector<int> st;
        for(auto it:intervals){
            st.push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            int ub = upper_bound(st.begin(),st.end(),intervals[i][1])-st.begin();
            ans += (ub-i-1);
        }
        return ans;
    }
};