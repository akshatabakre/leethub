class Solution {
public:
    int countDel(int x,map<int,int>& f,int k){
        int count = 0;
        for(auto it:f){
            int y = it.second;
            if(y<x){
                count+=y;
            }else if(y>x+k){
                count+=(y-x-k);
            }
        }
        return count;
    }
    int minimumDeletions(string word, int k) {
        map<int,int> f;
        for(auto ch:word){
            f[ch]++;
        }
        int ans = 1e9;
        for(auto it:f){
            ans = min(ans,countDel(it.second,f,k));
        }
        return ans;
    }
};