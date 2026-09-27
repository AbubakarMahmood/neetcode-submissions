#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count frequencies and find max_freq in a single pass
        std::unordered_map<int, int> counts;
        int max_freq = 0;
        for (int num : nums) {
            int freq = ++counts[num];
            if (freq > max_freq) {
                max_freq = freq;
            }
        }

        // Step 2: Allocate buckets sized strictly to max_freq + 1
        // Avoids allocating 100,000+ vector headers when max_freq is small
        std::vector<std::vector<int>> buckets(max_freq + 1);
        for (const auto& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        // Step 3: Collect exactly k elements starting directly from max_freq
        std::vector<int> result;
        result.reserve(k);

        for (int freq = max_freq; freq >= 1 && result.size() < k; --freq) {
            for (int num : buckets[freq]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};