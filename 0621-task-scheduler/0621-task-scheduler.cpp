class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        // Max heap to store frequencies
        priority_queue<int> maxHeap;
        for (auto& [task, f] : freq) {
            maxHeap.push(f);
        }

        int time = 0;

        while (!maxHeap.empty()) {
            int cycle = n + 1;
            vector<int> temp;

            while (cycle > 0 && !maxHeap.empty()) {
                int f = maxHeap.top();
                maxHeap.pop();
                if (f > 1) {
                    temp.push_back(f - 1);
                }
                time++;
                cycle--;
            }

            for (int remaining : temp) {
                maxHeap.push(remaining);
            }

            if (maxHeap.empty()) {
                break;
            }

            time += cycle; // Add idle time if there are still tasks left
        }

        return time;
    }
};
