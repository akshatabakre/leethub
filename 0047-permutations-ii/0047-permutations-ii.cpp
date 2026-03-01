class Solution {
public:
    map<int,int> choices;
    int n;
    vector<vector<int>> res;
    vector<int> perm;
    void rec(int level){
        if(level==n){
            res.push_back(perm);
            return;
        }
        for(auto ch:choices){
            if(ch.second>0){
                perm.push_back(ch.first);
                choices[ch.first]--;
                rec(level+1);
                choices[ch.first]++;
                perm.pop_back();
                
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         n = nums.size();
         for(int i:nums){
            choices[i]++;
         }
        rec(0);
        return res;
    }
};