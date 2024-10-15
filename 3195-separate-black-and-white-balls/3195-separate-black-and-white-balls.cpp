class Solution {
public:
    long long minimumSteps(string s) {
        long long mins = 0;
        int j = s.length()-1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                mins += (j-i);
                cout<<"placed "<<i<<" one at "<<j<<endl;
                j--;
            }
        }
        return mins;
    }
};