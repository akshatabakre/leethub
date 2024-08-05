class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        //map strings with their frequencies
        //create an int vector storing frequency of arr in order
        //then return the kth string
        unordered_map<string,int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        vector<int> a(arr.size());
        for(int i=0;i<a.size();i++){
            a[i] = freq[arr[i]];
        }
        int p = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]==1){
                p++;
                if(p==k){
                    return arr[i];
                }
            }
        }
        return "";
    }
};