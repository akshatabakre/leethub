class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> f;
        for(string word:words){
            f[word]++;
        }
        int ans = 0;
        bool midexists = false;
        string rev = "";
        for(auto i:f){
            string word = i.first;  int freq = i.second;
            //"aa"
            if(word[0]==word[1]){
                if(freq%2){
                    midexists = true;
                    ans+=(2*(freq-1));
                }else{
                    ans+=(2*freq);
                }
            }else{//"ab"
                rev+=word[1];   rev+=word[0];
                ans+=(4*min(freq,f[rev]));
                f[rev] = 0; f[word] = 0;
                rev = "";
            }
        }
        if(midexists){
            ans+=2;
        }
        return ans;
    }
};