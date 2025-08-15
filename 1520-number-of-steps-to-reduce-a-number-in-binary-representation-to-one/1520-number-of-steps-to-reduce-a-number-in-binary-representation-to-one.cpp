class Solution {
public:
    int numSteps(string s) {
        long long ans = 0;
        while(s!="1"){
            while(!s.empty() && s.back()=='0'){
                s.pop_back();
                ans++;
                cout<<"removed 0"<<endl;
            }
            if(s!="1"){
                int i = s.length()-1;
                while(i>=0 && s[i]=='1'){
                    s[i]='0';
                    i--;
                }
                if(i>=0){
                    s[i] = '1';
                    cout<<"added 1\n";
                    ans++;
                }else{
                    ans++;
                    ans+=s.length();
                    cout<<"removed all zeroes\n";
                    return ans;
                }
            }
        }
        return (int)ans;
    }
};