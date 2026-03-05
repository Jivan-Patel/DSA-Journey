class Solution {
public:
    int minBitFlips(int start, int goal) {
        string binaryStart = "";
        string binaryGoal = "";
        int flipCount = 0;
        while (start > 0) {
            if (start % 2)
                binaryStart += '1';
            else
                binaryStart += '0';
            start /= 2;
        }
        while (goal > 0) {
            if (goal % 2)
                binaryGoal += '1';
            else
                binaryGoal += '0';
            goal /= 2;
        }

        while (binaryGoal.size() > binaryStart.size()) 
            binaryStart += '0';
        while (binaryGoal.size() < binaryStart.size()) 
            binaryGoal += '0';
        int i = binaryStart.size() - 1;
        while (i >= 0) {
            if (binaryStart[i] != binaryGoal[i])
                flipCount++;
            i--;
        }
        return flipCount;
    }
};