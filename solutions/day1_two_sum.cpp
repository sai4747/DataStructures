#include <bits/stdc++.h>
using namespace std;

/*
- Two Sum — https://leetcode.com/problems/two-sum/
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * Constraints:
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * Only one valid answer exists.
 * Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 */
// Two Sum - return indices of the two numbers that add up to target

class Solution {
public:
    // Hash-map approach (preferred)
    // Time complexity: O(n) average, because each element does an O(1) unordered_map lookup/insert on average.
    // Space complexity: O(n) for the hash map storing seen values -> indices.
    // Returns the first pair found and exits early.
    // Signature uses a const reference to indicate the input is not modified.
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int,int> seen; // value -> index
        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            auto it = seen.find(need);
            if (it != seen.end()) return {it->second, i};
            seen[nums[i]] = i;
        }
        return {};
    }

    // Brute-force approach (kept for reference)
    // Time complexity: O(n^2) because of the nested loop checking every pair.
    // Space complexity: O(1) extra (ignoring output). The current implementation collects all matching
    // pairs into the result vector — this is NOT the usual LeetCode contract which expects a single pair.
    // Note: Having this overload with a non-const reference parameter causes overload-resolution to prefer
    // this (slower) function when calling twoSum on a non-const vector. Consider renaming to
    // `twoSumBruteForce` or removing it to avoid surprising behavior.
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (target == nums[i] + nums[j]) {
                    // Prefer to return immediately for the LeetCode contract (single pair).
                    // Here we push all matches — change to `return {i, j};` if you want the first pair only.
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return {};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto ans = sol.twoSum(nums, target);
    if (!ans.empty()) cout << "Indices: " << ans[0] << ", " << ans[1] << "\n";
    else cout << "No solution\n";
    return 0;
}
