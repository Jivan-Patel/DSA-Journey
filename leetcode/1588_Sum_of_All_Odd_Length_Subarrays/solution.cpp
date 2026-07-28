class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int totalSum = 0;
        for (int k = 1; k <= arr.size(); k += 2) {
            int low = 0, high = k, curSum = 0;
            for (int i = 0; i < k; i++) {
                curSum += arr[i];
            }
            totalSum += curSum;

            while (high < arr.size()) {
                curSum += arr[high] - arr[low];
                totalSum += curSum;
                high++;
                low++;
            }
        }
        return totalSum;
    }
};