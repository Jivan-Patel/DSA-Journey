class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int countA = 0, countB = 0;
        for(char ch : s) {
            if(ch == 'a') countA++;
            else countB++;
        }
        return abs(countA - countB);
    }
};