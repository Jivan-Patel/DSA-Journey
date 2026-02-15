class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
    set<int> s1;
    for (int num : nums) {
        s1.insert(num);
        int reverse = 0;
        while (num > 0) {
            reverse = reverse * 10 + num % 10;
            num = num/10;
        }
        s1.insert(reverse);
    }
    return s1.size();        
    }
};