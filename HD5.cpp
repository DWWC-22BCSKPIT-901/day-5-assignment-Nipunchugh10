#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        // Initialize two arrays for tracking max from the left and min from the right
        vector<int> leftMax(n), rightMin(n);

        // Fill leftMax array
        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }

        // Fill rightMin array
        rightMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], arr[i]);
        }

        // Calculate the maximum number of chunks
        int chunks = 0;
        for (int i = 0; i < n - 1; i++) {
            if (leftMax[i] <= rightMin[i + 1]) {
                chunks++;
            }
        }

        // Include the final chunk
        return chunks + 1;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> arr1 = {5, 4, 3, 2, 1};
    cout << "Input: arr = [5, 4, 3, 2, 1]\n";
    cout << "Output: " << solution.maxChunksToSorted(arr1) << endl;

    // Example 2
    vector<int> arr2 = {2, 1, 3, 4, 4};
    cout << "Input: arr = [2, 1, 3, 4, 4]\n";
    cout << "Output: " << solution.maxChunksToSorted(arr2) << endl;

    return 0;
}
