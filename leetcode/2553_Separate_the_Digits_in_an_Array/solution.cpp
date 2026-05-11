class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int num : nums) {
            vector<int> digit;
            while(num > 0) {
                digit.push_back(num%10);
                num /= 10;
            }
            for(int j =  digit.size() - 1; j >= 0; j--)
                res.push_back(digit[j]);
        }
        return res;
    }
};