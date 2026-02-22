class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.length();
        int ones = 0;
        for(char ch:t){
            ones += (ch=='1');
        }
        vector<int> mark(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(ones){
                    ones--;
                    s[i] = '1';
                    mark[i] = 1;
                }else{
                    break;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(!mark[i]){
                if(ones){
                    ones--;
                    s[i] = '0';
                }else{
                    break;
                }
            }
        }
        return s;
    }
};