class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size(), m = nums1.size();
        stack<int> st;
        map<int,int> mp;
        vector<int> ans(m,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<m;i++){
            if(mp.count(nums1[i])){
                ans[i] = mp[nums1[i]];
            }
        }
        return ans;
    }
};