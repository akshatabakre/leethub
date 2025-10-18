class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        multiset<pair<int,int>> st;
        for(int i:nums){
            st.insert({i-k,i+k});
        }
        int n = nums.size();
        int distnum = 0;
        int prev = -1e9;
        for(auto it:st){
            int x = max(prev+1,it.first);
            if(x<=it.second){
                prev = x;
                distnum++;
            }
        }
        return distnum;
    }
};