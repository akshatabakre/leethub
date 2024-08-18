class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        unordered_map<float,bool> m;
        vector<string> fractions;
        for(int i=2;i<=n;i++){//denominator
            for(int j=1;j<i;j++){//numerator
                if(m[float(j)/float(i)]==false){
                    m[float(j)/float(i)] = true;
                    string a;
                    a+=to_string(j);
                    a+='/';
                    a+=to_string(i);
                    fractions.push_back(a);
                }
            }
        }
        return fractions;
    }
};