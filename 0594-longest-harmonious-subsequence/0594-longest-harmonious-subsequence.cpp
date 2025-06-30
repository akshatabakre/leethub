class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> f;
        for(int i:nums){
            f[i]++;
        }
        if(f.size()==1){
            return 0;
        }
        int prevf = -1,prevnum = -1;;
        int maxi = 0;
        for(auto it:f){
            if(prevf!=-1 && it.first-prevnum==1){
                maxi = max(prevf+it.second,maxi);
            }
            prevnum = it.first;
            prevf = it.second;
        }
        return maxi;
    }
};