class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                if(freq[i]%2==0){
                    freq[i] = 2;
                }else{
                    freq[i] = 1;
                }
            }
        }
        int len = 0;
        for(int i:freq){
            len+=i;
        }
        return len;
    }
};