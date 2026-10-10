
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<int> freq(100001, 0);

        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            total += d;
        }

        if (total <= k) return 0;

        for (int d = 100000; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            long long cnt = freq[d];
            long long ops = min(k, cnt);

            freq[d] -= ops;
            freq[d - 1] += ops;
            k -= ops;
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};
