class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int n = digits.size();
        int c = 1;
        for(int i=n-1;i>=0;i--){
            v.push_back((digits[i]+c)%10);
            c = (digits[i]+c)/10;
        }
        if(c){
            v.push_back(c);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};