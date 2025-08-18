class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> pos(nums.begin(),nums.end());
        int n = moveTo.size();
        for(int i=0;i<n;i++){
            if(pos.find(moveFrom[i])!=pos.end()){
            pos.erase(moveFrom[i]);
            pos.insert(moveTo[i]);

            }
        }
        vector<int> ans;
        for(int i:pos){
            ans.push_back(i);
        }
        return ans;
    }
};