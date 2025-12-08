class Solution {
public:
    map<int,int> ref;
    int refl(int num){
        if(ref.count(num)){
            return ref[num];
        }
        int x = 0;
        int nu = num;
        while(nu){
            int r = nu % 2;
            x = x<<1;
            x|=r;
            nu/=2;
        }
        return ref[num] = x;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i:nums){
            v.push_back({refl(i),i});
        }
        sort(v.begin(),v.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = v[i].second;
        }
        return ans;
    }
};