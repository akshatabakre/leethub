class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size(), m = nums2.size();
        map<int,long long> f;
        for(int i=0;i<n;i++){
            f[nums1[i]]+=m;
        }
        for(int i=0;i<m;i++){
            f[nums2[i]]+=n;
        }
        for(auto i:f){
            if(i.second%2==1){
                ans = (ans^i.first);
            }
        }
        return ans;
    }
};