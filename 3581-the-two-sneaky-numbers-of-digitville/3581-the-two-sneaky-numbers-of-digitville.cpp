class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        set<int> st;
        vector<int> ans;
        for(int i:nums){
            if(st.count(i)){
                ans.push_back(i);
            }else{
                st.insert(i);
            }
        }
        return ans;
    }
};