class Solution {
public:
    static bool cmp(string& a,string& b){
        if(a.length()==b.length()){
            return (a<b);
        }
        return (a.length()>b.length());
    }
    bool check(string& a,string& b){
        int i=0, j=0;
        while(i<a.length()){
            if(a[i]==b[j]){
                i++;    j++;
            }else{
                i++;
            }
        }
        return (j==b.length());
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        int m = s.length();
        sort(dictionary.begin(),dictionary.end(),cmp);
        for(int i=0;i<n;i++){
            if(check(s,dictionary[i])){
                return dictionary[i];
            }
        }
        return "";
    }
};