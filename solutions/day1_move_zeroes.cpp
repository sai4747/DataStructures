#include <bits/stdc++.h>
using namespace std;

// Move Zeroes: move all zeros to the end while maintaining order of non-zero elements
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        for (int read = 0; read < (int)nums.size(); ++read) {
            if (nums[read] != 0) {
                nums[write++] = nums[read];
            }
        }
        while (write < (int)nums.size()) nums[write++] = 0;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    cout << "After moveZeroes: ";
    for (int x : nums) cout << x << ' ';
    cout << '\n';
    return 0;
}
