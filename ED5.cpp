#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    pair<int, int> findFirstAndLast(vector<int>& nums, int x) {
        int first = binarySearch(nums, x, true);
        int last = binarySearch(nums, x, false);
        return {first, last};
    }

private:
    // Helper function to perform binary search
    int binarySearch(vector<int>& nums, int x, bool findFirst) {
        int left = 0, right = nums.size() - 1, result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == x) {
                result = mid;
                if (findFirst) {
                    right = mid - 1; // Look for earlier occurrence
                } else {
                    left = mid + 1; // Look for later occurrence
                }
            } else if (nums[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x1 = 5;
    auto result1 = solution.findFirstAndLast(nums1, x1);
    cout << "Input: v[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}, X = 5\n";
    cout << "Output: " << result1.first << " " << result1.second << endl;

    // Example 2
    vector<int> nums2 = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    int x2 = 7;
    auto result2 = solution.findFirstAndLast(nums2, x2);
    cout << "Input: v[] = {1, 3, 5, 5, 5, 5, 7, 123, 125}, X = 7\n";
    cout << "Output: " << result2.first << " " << result2.second << endl;

    return 0;
}
