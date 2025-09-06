class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        int n = target;
        while(n>1){
            if(maxDoubles==0){
                ans += (n-1);
                break;
            }
            if(n%2){
                ans++;
                n--;
            }else{
                maxDoubles--;
                ans++;
                n/=2;
            }
        }
        return ans;
    }
};