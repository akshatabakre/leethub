class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        for(auto i:words){
            m[i]++;
        }
        int best=0;
        int counter=0;
        int best2=0;
        unordered_map<string,bool> mp;
        for(auto i:m){
            string s=i.first;
            string a=s;
            reverse(a.begin(),a.end());
            if(s==a){
                if(i.second%2==0){
                    best2+=i.second;
                }
                else{
                    best2+=(i.second-1);
                    best++;
                }
            }
            else if(mp.find(a)==mp.end() && m.count(a)){
                counter+=min(i.second,m[a]);
                mp[s]=true;
                mp[a]=true;
            }
        }
        cout<<counter<<" "<<best2<<" "<<best;
        
        return (4*counter+(2*min(best,1)+2*best2));

        
    }
};