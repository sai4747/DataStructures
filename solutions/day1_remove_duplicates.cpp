#include <bits/stdc++.h>
using namespace std;

// Remove Duplicates from Sorted Array
// Modify array in-place and return new length
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int write = 1; // next position to write unique value
        for (int read = 1; read < (int)nums.size(); ++read) {
            if (nums[read] != nums[read-1]) {
                nums[write++] = nums[read];
            }
        }
        return write;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = sol.removeDuplicates(nums);
    cout << "New length: " << k << "\n";
    cout << "Array: ";
    for (int i = 0; i < k; ++i) cout << nums[i] << " ";
    cout << '\n';
    return 0;
}
