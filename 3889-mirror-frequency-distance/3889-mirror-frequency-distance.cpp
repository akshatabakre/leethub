class Solution {
public:
    char mirror(char ch){
        if(ch>='0' && ch<='9'){
            return char('0'+('9'-ch));
        }
        return char('a'+25-(int)(ch-'a'));
    }
    int mirrorFrequency(string s) {
        map<char,int> f;
        for(char ch:s){
            f[ch]++;
        }
        int sum = 0;
        for(auto it:f){
            sum += abs(f[it.first]-f[mirror(it.first)]);
            f[it.first] = 0;
            f[mirror(it.first)] = 0;
        }
        return sum;
    }
};