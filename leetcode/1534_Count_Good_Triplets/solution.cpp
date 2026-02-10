class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int l = arr.size();
        for (int i = 0; i < l - 2; i++) {
            for (int j = i + 1; j < l - 1; j++) {
                for (int k = j + 1; k < l; k++) {
                    if (((arr[i] - arr[j] <= a) && (arr[j] - arr[i] <= a)) &&
                        ((arr[j] - arr[k] <= b) && (arr[k] - arr[j] <= b)) &&
                        ((arr[i] - arr[k] <= c) && (arr[k] - arr[i] <= c)))
                        count++;
                }
            }
        }
        return count;
    }
};