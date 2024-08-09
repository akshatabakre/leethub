class Solution {
public:
    int minimumSum(int num) {
        int sum;
        string n = to_string(num);
        sort(n.begin(),n.end());
        int n1 = (n[0]-'0')*10 + (n[3]-'0');
        int n2 = (n[1]-'0')*10 + (n[2]-'0');
        sum = n1 + n2;
        return sum;
    }
};