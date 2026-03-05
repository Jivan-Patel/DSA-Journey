class Solution {
public:
    int minOperations(string s) {
        char flag = '1';
        int count = 0;
        for (char digit : s) {
            if (flag == digit)
                count++;
            if (flag == '1')
                flag = '0';
            else
                flag = '1';
        }
        if (s.size() - count < count)
            count = s.size() - count;

        return count;
    }
};