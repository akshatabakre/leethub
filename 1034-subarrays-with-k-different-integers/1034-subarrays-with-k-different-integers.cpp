class Solution {
public:
    int countAtMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int head = -1, tail = 0;
        int ans = 0, n = nums.size(), distinct = 0;

        while (tail < n) {
            while (head + 1 < n && (freq[nums[head + 1]] > 0 || distinct < k)) {
                head++;
                if (freq[nums[head]] == 0) distinct++;
                freq[nums[head]]++;
            }

            ans += (head - tail + 1);

            freq[nums[tail]]--;
            if (freq[nums[tail]] == 0) distinct--;
            tail++;

            if (tail > head) {
                head = tail - 1;
            }
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};
