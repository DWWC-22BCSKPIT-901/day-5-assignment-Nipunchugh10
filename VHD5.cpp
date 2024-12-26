#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom GCD function
int customGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Solution {
public:
    vector<int> gcdQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> gcdPairs;
        int n = nums.size();

        // Compute all GCD pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdPairs.push_back(customGCD(nums[i], nums[j]));
            }
        }

        // Sort the GCD pairs in ascending order
        sort(gcdPairs.begin(), gcdPairs.end());

        // Prepare the answer for each query
        vector<int> result;
        for (int q : queries) {
            if (q >= 0 && q < gcdPairs.size()) {
                result.push_back(gcdPairs[q]);
            } else {
                result.push_back(-1); // Placeholder for out-of-bounds queries
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {2, 3, 4};
    vector<int> queries1 = {0, 2, 2};
    vector<int> result1 = solution.gcdQueries(nums1, queries1);
    cout << "Output: ";
    for (int r : result1) cout << r << " ";
    cout << endl;

    // Example 2
    vector<int> nums2 = {4, 4, 2, 1};
    vector<int> queries2 = {5, 3, 1, 0};
    vector<int> result2 = solution.gcdQueries(nums2, queries2);
    cout << "Output: ";
    for (int r : result2) cout << r << " ";
    cout << endl;

    // Example 3
    vector<int> nums3 = {2, 2};
    vector<int> queries3 = {0, 0};
    vector<int> result3 = solution.gcdQueries(nums3, queries3);
    cout << "Output: ";
    for (int r : result3) cout << r << " ";
    cout << endl;

    return 0;
}
