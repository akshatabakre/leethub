class Solution {
public:
    string largestGoodInteger(string num) {
        int largest = -1;
        int n = num.length();
        for(int i=0;i+2<n;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                largest = max(num[i]-'0',largest);
            }
        }
        string s = "";
        if(largest==-1){
            return s;
        }
        char ch = char(largest+'0');
        s += ch;    s+=ch;      s+=ch;
        return s;
    }
};