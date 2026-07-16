class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> velqoradin = nums; 
        
        int n = velqoradin.size();
        vector<long long> prefixGcd(n);
        
        long long maxSoFar = 0;
        
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, (long long)velqoradin[i]);
            prefixGcd[i] = __gcd((long long)velqoradin[i], maxSoFar);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            ans += __gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};