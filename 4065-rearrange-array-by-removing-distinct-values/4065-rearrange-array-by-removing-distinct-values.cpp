class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        while(ans.size()<n){
            cout<<1<<endl;
            for(auto it:mp){
                int f = it.second;
                if(f==0)    continue;
                ans.push_back(it.first);
                cout<<it.first<<" "<<f<<endl;
                f--;
                mp[it.first] = f;
            }
        }
        return ans;
    }
};