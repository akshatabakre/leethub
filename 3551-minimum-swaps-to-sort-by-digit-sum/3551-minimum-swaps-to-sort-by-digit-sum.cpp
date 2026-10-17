class Solution {
public:
    int digitsum(int n){
        int ans = 0;
        while(n){
            ans += (n%10);
            n/=10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        map<int,int> indic;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int ds = digitsum(nums[i]);
            v.push_back({ds,nums[i]});
            indic[nums[i]] = i;
        }
        sort(v.begin(),v.end());
        int swaps = 0;
        for(int i=0;i<n;i++){
            int val = v[i].second;
            int ind = indic[val];
            if(i!=ind){
                swap(nums[i],nums[ind]);
                indic[nums[i]] = i;
                indic[nums[ind]] = ind;
                swaps++;
            }
        }
        return swaps;
    }
};