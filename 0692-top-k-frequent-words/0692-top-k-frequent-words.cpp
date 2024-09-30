class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> f;
        for(int i=0;i<words.size();i++){
            pair<int,string> p;
            p.first = count(words.begin(),words.end(),words[i]);
            p.second = words[i];
            if(count(f.begin(),f.end(),p)==0){
                f.push_back(p);
            }   
        }
        auto cmp = [](pair<int,string>& a,pair<int,string>& b){
            if(a.first==b.first){
                return a<b;
            }else{
                return a.first>b.first;
            }
        };
        sort(f.begin(),f.end(),cmp);
        vector<string> res;
        for(int i=0;i<k;i++){
            pair<int,string> p = f[i];
            res.push_back(p.second);
        }
        return res;
    }
};