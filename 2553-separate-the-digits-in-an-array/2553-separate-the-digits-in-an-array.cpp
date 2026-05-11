class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> dig;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            vector<int> v;
            while(x){
                v.push_back(x%10);
                x/=10;
            }
            for(int j=v.size()-1;j>=0;j--){
                dig.push_back(v[j]);
            }
        }
        return dig;
    }
};