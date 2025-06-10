class Solution {
public:
    int maxDifference(string s) {
        map<char,int> f;
        for(auto i:s){
            f[i]++;
        }
        int maxodd,mineven;
        maxodd = 0,mineven = s.length();
        for(auto i:f){
            int fr = i.second;
            maxodd = (fr%2==1)? max(maxodd,fr) : maxodd;
            // maxeven = (fr%2==0)? max(maxeven,fr) : maxeven;
            // minodd = (fr%2==1)? min(minodd,fr) : minodd;
            mineven = (fr%2==0)? min(mineven,fr) : mineven;
        }
        return maxodd-mineven;
    }
};