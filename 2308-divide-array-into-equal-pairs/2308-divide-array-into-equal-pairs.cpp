class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> f;
        for(int i:nums){
            f[i]++;
        }
        for(auto i:f){
            if(i.second%2){
                return false;
            }
        }
        return true;
    }
};