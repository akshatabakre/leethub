class Bank {
public:
    int n;
    vector<long long> balance;
    Bank(vector<long long>& balance) {
        this->n = balance.size();
        this->balance = balance;
    }
    
    bool validAcc(int acc){
        return (acc>=1 && acc<=n);
    }
    bool transfer(int account1, int account2, long long money) {
        if(!validAcc(account1) || !validAcc(account2)){
            return false;
        }
        if(balance[account1 - 1] < money){
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!validAcc(account)){
            return false;
        }
        balance[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!validAcc(account)){
            return false;
        }
        if(balance[account-1] < money){
            return false;
        }
        balance[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */