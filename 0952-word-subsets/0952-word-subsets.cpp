class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        vector<string> ans;
        // for(int i=0;i<n;i++){
        //     map<char,int> freq;
        //     for(char ch:words1[i]){
        //         freq[ch]++;
        //     }
        //     bool valid = true;
        //     for(int j=0;j<m;j++){
        //         map<char,int> f2;
        //         for(char ch:words2[j]){
        //             f2[ch]++;
        //         }
        //         for(char ch:words2[j]){
        //             if(f2[ch]>freq[ch]){
        //                 valid = false;
        //                 break;
        //             }
        //         }
        //     }
        //     if(valid){
        //         ans.push_back(words1[i]);
        //     }
        // }
        // return ans;
        map<char,int> maxreqd;
        for(int i=0;i<m;i++){
            for(char ch:words2[i]){
                // maxreqd[ch] = max(count(words2[i].begin(),words2[i].end(),ch),maxreqd[ch]);
                if(maxreqd[ch]<count(words2[i].begin(),words2[i].end(),ch)){
                    maxreqd[ch] = count(words2[i].begin(),words2[i].end(),ch);
                }
            }
        }
        for(int i=0;i<n;i++){
            bool valid = true;
            // for(char ch:words1[i]){
            //     if(maxreqd[ch]>count(words1[i].begin(),words1[i].end(),ch)){
            //         valid = false;
            //         break;
            //     }
            // }
            for(auto j:maxreqd){
                int f = count(words1[i].begin(),words1[i].end(),j.first);
                if(f==0){
                    valid = false;
                    break;
                } else if(f!=0 && j.second>f){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};