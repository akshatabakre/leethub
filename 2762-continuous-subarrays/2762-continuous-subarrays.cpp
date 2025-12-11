class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        #define int long long
        int n = nums.size();
        int l = 0, r = -1;
        int ans = 0;
        multiset<int> ms;
        while(l<n){
            while(r+1<n && (ms.empty() || (max((long long)nums[r+1],(long long)*(ms.rbegin()))-min((long long)nums[r+1],(long long)*(ms.begin())))<=2LL)){
                r++;
                ms.insert(nums[r]);
            }
            ans+=(r-l+1);
            cout<<(r-l+1)<<endl;
            if(l>r){
                l++;
                r = l-1;
            }else{
                ms.erase(ms.find(nums[l]));
                l++;
            }
        }
        return ans;
        #undef int
    }
};