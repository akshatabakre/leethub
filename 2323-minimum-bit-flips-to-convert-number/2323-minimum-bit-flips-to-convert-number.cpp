class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xored = start^goal;
        int ans = 0;
        for(int i=0;i<32;i++){
            if((xored>>i)&1){
                ans++;
            }
        }
        return ans;
    }
};