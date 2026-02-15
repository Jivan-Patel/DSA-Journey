class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;    
    for(int i = left; i <= right; i++) {
        int test = i;
        bool valid = true;
        while (test > 0) {
            int digit = test % 10;
            if (digit == 0 || i % digit != 0) {
                valid = false;
                break;
            }
            test = test / 10;
        }
        if (valid) res.push_back(i);
    }
    return res;       
    }
};