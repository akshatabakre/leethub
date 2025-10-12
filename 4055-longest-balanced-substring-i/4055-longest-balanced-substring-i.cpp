class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            map<char,int> m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int len = j-i+1;
                int dc = m.size();
                if(len%dc){
                    continue;
                }
                bool valid = true;
                for(auto it:m){
                    if(it.second!=(len/dc)){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    ans = max(len,ans);
                }
            }
        }
        return ans;
    }
};