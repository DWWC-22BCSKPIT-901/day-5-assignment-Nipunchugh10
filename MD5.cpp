#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int closestToZero(vector<int>& arr, int n) {
        // Sort the array
        sort(arr.begin(), arr.end());
        
        int left = 0, right = n - 1;
        int closestSum = INT_MAX;
        int maxSumClosestToZero = INT_MIN;

        // Two-pointer approach
        while (left < right) {
            int sum = arr[left] + arr[right];

            // Update closest sum to zero
            if (abs(sum) < abs(closestSum)) {
                closestSum = sum;
                maxSumClosestToZero = sum;
            } else if (abs(sum) == abs(closestSum)) {
                // If the sums are equally close to zero, choose the maximum sum
                maxSumClosestToZero = max(maxSumClosestToZero, sum);
            }

            // Move pointers
            if (sum < 0) {
                left++; // Increase the sum by moving left pointer
            } else {
                right--; // Decrease the sum by moving right pointer
            }
        }

        return maxSumClosestToZero;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> arr1 = {-8, -66, -60};
    int n1 = arr1.size();
    cout << "Input: arr[] = {-8, -66, -60}\n";
    cout << "Output: " << solution.closestToZero(arr1, n1) << endl;

    // Example 2
    vector<int> arr2 = {-21, -67, -37, -18, 4, -65};
    int n2 = arr2.size();
    cout << "Input: arr[] = {-21, -67, -37, -18, 4, -65}\n";
    cout << "Output: " << solution.closestToZero(arr2, n2) << endl;

    return 0;
}
