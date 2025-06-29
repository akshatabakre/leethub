class Solution {
public:
    int calcLCP(vector<string>& words,int i1,int i2){
        if(i1<0 || i2>words.size()-1){
            return 0;
        }
        int p = 0;
        while(p<min(words[i1].length(),words[i2].length()) && words[i1][p]==words[i2][p]){
            p++;
        }
        return p;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();

        vector<int> lcp(n-1,0);
        for(int i=0;i<n-1;i++){
            int p = 0;
            while(p<min(words[i].length(),words[i+1].length()) && words[i][p]==words[i+1][p]){
                p++;
            }
            lcp[i] = p;
            // cout<<lcp[i]<<endl;
        }

        multiset<int> ms(lcp.begin(),lcp.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(i>0){
                ms.erase(ms.find(lcp[i-1]));
            }
            if(i<n-1)
                ms.erase(ms.find(lcp[i]));
            int a = 0;
            if(!ms.empty())
                a = *ms.rbegin();
            if(i<n-1)
                ms.insert(lcp[i]);
            if(i>0){
                ms.insert(lcp[i-1]);
            }
            ans[i] = max(calcLCP(words,i-1,i+1),a);
        }
        return ans;
    }
};