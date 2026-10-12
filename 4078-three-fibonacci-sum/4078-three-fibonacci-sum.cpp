class Solution {
public:
    bool threeFibonacciSum(int n) {
        //if n is 2*x where x appears in fib sequence
        if(n%2) return false;
        int a=0,b=1;
        while(a+b<n/2){
            int x = a+b;
            a = b;
            b = x;
        }
        return (a+b==n/2);
    }
};