class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if(n < k) return 0;

        int sum = 0, low = 0, high = k, res = 0;
        for(int i = 0; i < k; i++) sum += arr[i];
        if(sum / k >= threshold) res++;

        while(high < n) {
            sum += arr[high] - arr[low];
            if(sum / k >= threshold) res++;
            high++; 
            low++;
        }

        return res;
    }
};