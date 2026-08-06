class Solution {
public:
    int prod(int x){
        int ans = 1;
        while(x){
            ans = ans*(x%10);
            x/=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int x = n;
        while(prod(x)%t!=0){
            x++;
        }
        return x;
    }
};