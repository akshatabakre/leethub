class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = strs.size(),len = s.length();
        vector<bool> ans(n);

        int sz = 0;
        int so = 0;
        for(char ch:s){
            if(ch=='0')     sz++;
            if(ch=='1')     so++;
        }

        for(int i=0;i<n;i++){
            string w = strs[i];
            int z = 0, o = 0, q = 0;
            for(char ch:w){
                if(ch=='0')     z++;
                if(ch=='1')     o++;
                if(ch=='?')     q++;
            }
            int zn = sz-z;
            int on = so - o;
            if(zn<0 || on<0 || q!=on+zn){
                ans[i] = false;
                continue;
            }

            for(int k=0;k<len;k++){
                if(w[k]=='?'){
                    if(zn>0){
                        w[k] = '0';
                        zn--;
                    }else{
                        w[k] = '1';
                        on--;
                    }
                }
            }

            set<int> zero;
            for(int k=0;k<len;k++){
                if(s[k]=='0'){
                    zero.insert(k);
                }
            }

            // for(auto k:zero){
            //     cout<<k<<" ";
            // }
            // cout<<endl;
            string str = s;
            bool flag = true;
            for(int k=0;k<len;k++){
                if(str[k]=='1' && w[k]=='0'){
                    auto it = zero.upper_bound(k);
                    if(it!=zero.end()){
                        // cout<<*it<<" "<<k<<endl;
                        swap(str[k],str[*it]);
                        zero.erase(it);
                    }else{
                        flag = false;
                        break;
                    }
                }else if(str[k]=='0' && w[k]=='1'){
                    flag = false;
                    break;
                }
            }

            ans[i] = flag;
        }

        return ans;
    }
};
