class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=0;i<n;i++){
            int m = merged.size();
            if(merged[m-1][1]>=intervals[i][0]){
                merged[m-1][1] = max(intervals[i][1],merged[m-1][1]);
            }else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};