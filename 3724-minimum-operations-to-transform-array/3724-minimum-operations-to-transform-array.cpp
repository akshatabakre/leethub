class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        #define int long long
        int n = nums1.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(nums1[i]-nums2[i]);
        }
        if(nums2.size()==n){
            return ans;
        }
        ans++;
        int c = 1e9;
        int num = nums2[n];
        for(int i=0;i<n;i++){
            int mini = min(nums1[i],nums2[i]);
            int maxi = max(nums1[i],nums2[i]);
            if(num>=mini && num<=maxi){
                c = 0;
            }else{
                c = min(c,min(abs(num-nums2[i]),abs(num-nums1[i])));
            }
        }
        ans+=c;
        return ans;
        #undef int
    }
};