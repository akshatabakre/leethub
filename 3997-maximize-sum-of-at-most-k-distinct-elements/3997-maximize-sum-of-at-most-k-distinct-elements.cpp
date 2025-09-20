class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> s;
        for(int i:nums){
            s.insert(i);
            if(s.size()>k){
                s.erase(s.begin());
            }
        }
        vector<int> ans;
        for(int i:s){
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};