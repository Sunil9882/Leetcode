class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;

    // Find the left non-decreasing part
    int i = 0;
    while (i < n - 1 && arr[i] <= arr[i + 1]) {
        i++;
    }

    // If the whole array is non-decreasing
    if (i == n - 1) return 0;

    // Find the right non-decreasing part
    int j = n - 1;
    while (j > 0 && arr[j - 1] <= arr[j]) {
        j--;
    }

    // Calculate the minimum length to remove
    int min_length = min(n - i - 1, j); // Remove from either left or right

    // Try to merge left and right parts
    int left = 0;
    while (left <= i) {
        while (j < n && arr[left] > arr[j]) {
            j++;
        }
        min_length = min(min_length, j - left - 1);
        left++;
    }

    return min_length;
}

};