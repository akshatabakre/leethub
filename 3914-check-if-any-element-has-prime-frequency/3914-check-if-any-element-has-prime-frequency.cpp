class Solution {
public:

    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> prime(101,1);
        prime[1] = 0;
        for(int i=2;i<=100;i++){
            if(prime[i]){
                for(int j=i*i;j<=100;j+=i){
                    prime[j] = 0;
                }
            }
        }
        map<int,int> f;
        for(int num:nums){
            f[num]++;
        }
        for(auto it:f){
            if(prime[it.second]){
                return true;
            }
        }
        return false;
    }
};