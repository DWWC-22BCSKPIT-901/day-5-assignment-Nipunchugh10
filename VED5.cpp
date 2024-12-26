#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Target is on the right side
            } else {
                right = mid - 1; // Target is on the left side
            }
        }

        // If target is not found, `left` will be the insertion position
        return left;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Input: nums = [1,3,5,6], target = 5 -> Output: " << solution.searchInsert(nums1, target1) << endl;

    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Input: nums = [1,3,5,6], target = 2 -> Output: " << solution.searchInsert(nums2, target2) << endl;

    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Input: nums = [1,3,5,6], target = 7 -> Output: " << solution.searchInsert(nums3, target3) << endl;

    return 0;
}
