class Solution {
public:
    int minBitFlips(int start, int goal) {
        // int xored = start^goal;
        int ans = 0;
        for(int i=0;i<32;i++){
            // if((xored>>i)&1){
            //     ans++;
            // }
            int n1 = (start>>i)&1;
            int n2 = (goal>>i)&1;
            if(n1!=n2){
                ans++;
            }
        }
        return ans;
    }
};