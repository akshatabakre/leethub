class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibs;
        int a = 0, b = 1;
        fibs.push_back(0);
        fibs.push_back(1);
        while(b<1000100000){
            int c = a+b;
            fibs.push_back(c);
            a = b;
            b = c;
        }
        int cnt = 0;
        while(k){
            cnt++;
            int ind = upper_bound(fibs.begin(),fibs.end(),k)-fibs.begin();
            ind--;
            k-=fibs[ind];
        }
        return cnt;
    }
};