class Solution {
public:
    vector<int> kmpFind(string s){
        int n = s.length();
        vector<int> kmp(n+1,-1);
        int i=0, j =-1;
        while(i<n){
            while(j!=-1 && s[i]!=s[j]){
                j = kmp[j];
            }
            i++;
            j++;
            kmp[i] = j;
        }
        return kmp;
    }
    string shortestPalindrome(string s) {
        int n = s.length();
        string str = s;
        str+='#';
        for(int i=n-1;i>=0;i--){
            str+=s[i];
        }
        vector<int> kmp = kmpFind(str);
        int ind = *kmp.rbegin();
        string ans = "";
        for(int i=n-1;i>=ind;i--){
            ans+=s[i];
        }
        for(int i=0;i<n;i++){
            ans+=s[i];
        }
        return ans;
    }
};