class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0,n=s.length();
        unordered_map<char,bool> m1;
        for(int i=0;i<n-2;i++){
            if(m1[s[i]]==false){
            unordered_map<char,bool> m2;
                for(int j=n-1;j>i+1;j--){
                    if(s[i]==s[j] && m2[s[j]]==false){
                        unordered_map<char,int> ch;
                        int dist = 0;
                        for(int k=i+1;k<j;k++){
                            if(ch[s[k]]==0){
                                dist++;
                                ch[s[k]] = 1;
                            }
                        }
                        ans+=dist;
                        cout<<s[i]<<" "<<s[j]<<" "<<dist<<endl;
                    }
                    m2[s[j]] = true;
                }
            }
            m1[s[i]] = true;
        }
        return ans;
    }
};