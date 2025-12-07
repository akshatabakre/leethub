class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        int s = low;
        if(low%2==0){
            s++;
        }
        for(;s<=high;s+=2){
            ans++;
        }
        return ans;
    }
};