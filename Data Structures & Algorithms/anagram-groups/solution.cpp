#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Key: sorted string, Value: list of matching original strings
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (const std::string& word : strs) {
            std::string key = word;
            std::sort(key.begin(), key.end()); // "cat" -> "act"
            groups[key].push_back(word);        // Store original "cat" in "act" bucket
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(groups.size());

        // Extract the grouped lists out of the map
        for (auto& pair : groups) {
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};
