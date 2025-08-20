class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        #define int long long
        int n = nums1.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i] = {nums2[i],nums1[i]};
        }
        sort(v.begin(),v.end());
        int sum = 0;
        int ans = 0;
        multiset<int> ms;
        for(int i=n-1;i>=0;i--){
            int ksum = v[i].second;
            if(ms.size()<k-1){
                ms.insert(v[i].second);
                sum+=v[i].second;
                continue;
            }else{
                ksum+=sum;
                ans = max(ans,v[i].first*ksum);
            }
            sum+=v[i].second;
            ms.insert(v[i].second);
            sum-=*(ms.begin());
            ms.erase(ms.find(*(ms.begin())));

        }
        return ans;
        #undef int
    }
};