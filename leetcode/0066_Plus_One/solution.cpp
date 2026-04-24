class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        vector<int> res;
        while(i >= 0 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }
        if(i >= 0) {
            digits[i]++;
        }
        else {
            res.push_back(1);
        }
        for(int digit : digits) 
            res.push_back(digit);
        return res;
    }
};