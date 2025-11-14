#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimal O(log(min(n,m))) solution using binary search on the smaller array.
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
        int n = (int)A.size();
        int m = (int)B.size();
        if (n == 0 && m == 0) return 0.0; // no elements
        // Ensure A is the smaller array
        if (n > m) return findMedianSortedArrays(B, A);

        int low = 0, high = n;
        while (low <= high) {
            int i = (low + high) / 2; // partition A
            int j = (n + m + 1) / 2 - i; // partition B so that left halves have (n+m+1)/2 elements

            int Aleft = (i == 0) ? INT_MIN : A[i-1];
            int Aright = (i == n) ? INT_MAX : A[i];
            int Bleft = (j == 0) ? INT_MIN : B[j-1];
            int Bright = (j == m) ? INT_MAX : B[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                // correct partition
                if ((n + m) % 2 == 1) {
                    return static_cast<double>(max(Aleft, Bleft));
                } else {
                    double leftMax = static_cast<double>(max(Aleft, Bleft));
                    double rightMin = static_cast<double>(min(Aright, Bright));
                    return (leftMax + rightMin) / 2.0;
                }
            } else if (Aleft > Bright) {
                // move partition in A to left
                high = i - 1;
            } else {
                // Aleft <= Bright is false implies Bleft > Aright -> move partition in A to right
                low = i + 1;
            }
        }
        return 0.0; // should not reach here for valid input
    }
};

// Simple demo / test harness
int main() {
    Solution sol;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << "median = " << sol.findMedianSortedArrays(a, b) << "\n"; // expect 2

    vector<int> c = {1, 2};
    vector<int> d = {3, 4};
    cout << "median = " << sol.findMedianSortedArrays(c, d) << "\n"; // expect 2.5

    vector<int> e = {};
    vector<int> f = {1};
    cout << "median = " << sol.findMedianSortedArrays(e, f) << "\n"; // expect 1

    return 0;
}
