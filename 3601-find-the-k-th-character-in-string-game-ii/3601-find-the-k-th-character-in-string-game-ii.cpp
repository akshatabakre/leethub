class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        int ones = 0;
        while(k){
            int grp = log2(k);
            ones+=operations[grp];
            k-=pow(2,grp);
        }
        return 'a' + (ones%26);
    }
};