#define ll long long
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> series(rowIndex + 1, 1);
        for (ll i = 1; i <= rowIndex; i++) {
            series[i] = series[i - 1] * (rowIndex - i + 1) / i;
        }
        return series;
    }
};