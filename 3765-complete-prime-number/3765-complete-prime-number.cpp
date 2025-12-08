class Solution {
public:
    #define int long long
    bool isprime(int n){
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
    bool completePrime(int num) {
        string numb = to_string(num);
        int n = numb.length();
        for(int i=0;i<n;i++){
            if(i && !isprime(stoi(numb.substr(0,i)))){
                return false;
            }
            if(!isprime(stoi(numb.substr(i)))){
                return false;
            }
        }
        return true;
        #undef int
    }
};