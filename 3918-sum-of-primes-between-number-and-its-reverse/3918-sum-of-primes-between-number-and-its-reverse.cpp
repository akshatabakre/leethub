class Solution {
public:

    bool isPrime(int n){
        if(n==1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string num = to_string(n);
        while(!num.empty() && num.back()=='0'){
            num.pop_back();
        }
        reverse(num.begin(),num.end());
        int r = stoi(num);

        int mini = min(n,r), maxi = max(n,r);

        int sum = 0;

        for(int i=mini;i<=maxi;i++){
            int x = i;
            if(isPrime(x)){
                sum += x;
            }
        }
        return sum;
    }
};