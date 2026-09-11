#include <unordered_set>
#include <vector>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
    // If there are 0 or 1 elements, duplicates are impossible
    if (nums.size() <= 1) {
        return false;
    }

    std::unordered_set<int> seen;
    seen.reserve(nums.size());// Avoids rehashing

    for (int num : nums) {
        if (!seen.insert(num).second) {//check the iterator for succes
            return true;
        }
    }
    return false;
}
};