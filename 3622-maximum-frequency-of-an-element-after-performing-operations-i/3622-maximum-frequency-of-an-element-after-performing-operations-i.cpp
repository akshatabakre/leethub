#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& n, int k, int o) {
        
        const int M = 100000;
        int f = k;
        int s = M + 2 * k + 5; 
        
        vector<int> d(s, 0); 
        
        unordered_map<int, int> m;

        for (int x : n) {
            m[x]++;
            
            int a = x - k;
            int b = x + k;
            
            int p = a + f;
            int q = b + f;
            
            if (p >= 0 && p < s) {
                d[p]++;
            }
            
            if (q + 1 < s) {
                d[q + 1]--;
            }
        }
        
        int r = 0;
        int c = 0; 

        for (int i = 0; i < s; i++) {
            c += d[i]; 
            
            int t = i - f;
            
            int z = 0;
            if (m.count(t)) {
                z = m[t];
            }
            
            int y = c - z;
            
            int w = min(y, o);
            
            int g = z + w;
            
            r = max(r, g);
        }
        
        return r;
    }
};