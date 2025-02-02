class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> v;
        v = nums;
        sort(v.begin(),v.end());
        int n = v.size();
        for(int i=0;i<n;i++){
            v.push_back(v[i]);
        }
        bool flag = false;
        for(int i=0;i<n;i++){
            if(v[i]==nums[0]){
                bool f = true;
                int ind = 0;
                for(int j=i;j<n+i;j++){
                    if(v[j]==nums[ind]){
                        ind++;
                    }else{
                        f = false;
                        break;
                    }
                }
                if(f){
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
};