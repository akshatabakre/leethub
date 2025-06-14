class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, have;
        for (char c : t) need[c]++;
        
        int required = need.size();
        int formed = 0;

        int head = -1, tail = 0;
        int minLen = INT_MAX, start = 0;
        int n = s.length();

        while (tail < n) {
            while (head + 1 < n && formed < required) {
                head++;
                char c = s[head];
                have[c]++;
                if (need.count(c) && have[c] == need[c]) {
                    formed++;
                }
            }

            if (formed == required && head - tail + 1 < minLen) {
                minLen = head - tail + 1;
                start = tail;
            }

            char c = s[tail];
            if (need.count(c) && have[c] == need[c]) {
                formed--;
            }
            have[c]--;
            tail++;

            if (tail > head) {
                head = tail - 1;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
