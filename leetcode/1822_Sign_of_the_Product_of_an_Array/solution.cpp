class Solution {
public:
    int arraySign(vector<int>& nums) {
    bool isNegative = false;
    for(int num : nums) {
        if(num < 0) isNegative = !isNegative;
        if(num == 0) return 0;
    }
    return (isNegative) ? -1 : 1;      
    }
};