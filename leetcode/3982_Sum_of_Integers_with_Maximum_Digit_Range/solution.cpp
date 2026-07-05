class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans = 0, maxRange = 0;

        for(int n : nums) {
            int s = 11, l = -1;
            int temp = n;

            while(temp > 0) {
                int d = temp % 10;
                s = min(s, d);
                l = max(l, d);
                temp /= 10;
            }

            if(l - s > maxRange) {
                maxRange = l - s;
                ans = n;
            } 
            else if(l - s == maxRange) ans += n;
        }

        return ans;
    }
};