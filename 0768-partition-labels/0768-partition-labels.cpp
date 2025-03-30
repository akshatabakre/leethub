class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> lastocc;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(lastocc.find(s[i])==lastocc.end()){
                lastocc[s[i]] = i;
            }
        }
        int start = 0, end = 0, it = start;
        vector<int> result;
        while(it<n){
            if(lastocc[s[it]]>end){
                end = lastocc[s[it]];
            }
            if(it==end){
                result.push_back(end-start+1);
                start = end+1;
                end = start;
                it = start;
            }else{
                it++;
            }
        }
        return result;
    }
};