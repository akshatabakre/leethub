class Solution {
public:

    bool evencheck(vector<int>&nums){
        for(int i:nums){
            if(i%2==1){
                return false;
            }
        }
        return true;
    }

    bool oddcheck(vector<int>&nums){
        int minodd = -1;
        for(int i:nums){
            if(i%2==1){
                if(minodd==-1){
                    minodd = i;
                }
            }else{
                if(minodd==-1){
                    return false;
                }
            }
        }
        return true;
    }

    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(evencheck(nums)||oddcheck(nums)){
            return true;
        }
        return false;
    }
};