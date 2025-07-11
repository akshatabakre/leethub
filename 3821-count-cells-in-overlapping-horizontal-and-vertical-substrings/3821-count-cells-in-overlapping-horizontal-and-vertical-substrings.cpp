class Solution {
public:
    vector<int> KMPFind(string s){
        int n = s.length();
        vector<int> kmp(n+1,-1);
        int i=0,j=-1;
        while(i<n){
            while(j!=-1 && s[i]!=s[j]){
                j = kmp[j];
            }
            i++;
            j++;
            kmp[i] = j;
        }
        return kmp;
    }
    int countCells(vector<vector<char>>& grid, string pattern) {
        //horiz -> n*i + j, vertical = m*j + i
        int m = grid.size(), n = grid[0].size();
        string h = "", v = "";
        for(int i=0;i<m*n;i++){
            h+='.';
            v+='.';
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                h[n*i + j] = grid[i][j];
                v[m*j + i] = grid[i][j];
            }
        }
        string hstr = pattern, vstr = pattern;
        hstr+='#';  vstr+='#';
        for(int i=0;i<m*n;i++){
            hstr+=h[i];
            vstr+=v[i];
        }
        vector<char> hmark(m * n, 0), vmark(m * n, 0);
        int p = pattern.size();
        vector<int> HKMP = KMPFind(hstr), VKMP = KMPFind(vstr);
    
        HKMP.erase(HKMP.begin(), HKMP.begin() + p + 2);
        VKMP.erase(VKMP.begin(), VKMP.begin() + p + 2);

        int st = -1, ed = -1;
        for (int i = HKMP.size() - 1; i >= 0; i--) {
            if (HKMP[i] == p) { 
                st = i; 
                ed = st - p + 1; 
            }
            if (i <= st && i >= ed) 
                hmark[i] = 1;
        }
        st = -1, ed = -1;
        for (int i = VKMP.size() - 1; i >= 0; i--) {
            if (VKMP[i] == p) { 
                st = i; 
                ed = st - p + 1; 
            }
            if (i <= st && i >= ed) 
                vmark[i] = 1;
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(hmark[n*i + j] && vmark[m*j + i]){
                    ans++;
                }
            }
        }
        return ans;
    }
};