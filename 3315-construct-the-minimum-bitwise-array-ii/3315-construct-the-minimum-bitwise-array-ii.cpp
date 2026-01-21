class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            vector<int> v;
            int x = nums[i];
            if(x%2==0){
                ans.push_back(-1);
                continue;
            }
            while(x>0){
                v.push_back(x%2);
                x/=2;
            }
            int j=0;
            while(j<v.size() && v[j]==1){
                j++;
            }
            j--;
            v[j] = 0;
            int a = 0;
            int y = 1;
            for(int j:v){
                a = (j*y + a);
                y*=2;
            }
            ans.push_back(a);
        }
        return ans;
    }
};