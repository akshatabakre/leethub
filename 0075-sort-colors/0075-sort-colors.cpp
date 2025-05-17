class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ind = 0;
        for(auto i:m){
            for(int j=0;j<i.second;j++){
                nums[ind++] = i.first;
            }
        }
        return;
    }
};