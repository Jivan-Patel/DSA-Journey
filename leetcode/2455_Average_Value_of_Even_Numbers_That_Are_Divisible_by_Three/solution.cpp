class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for(int n : nums) {
            if(n % 6 == 0) {
                sum += n;
                count++;
            }
        }

        return count != 0 ? sum / count : 0;
    }
};