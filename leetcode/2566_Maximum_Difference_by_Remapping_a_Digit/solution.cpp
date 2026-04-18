class Solution {
public:
    int minMaxDifference(int num) {
        string temp = to_string(num);
        char changeNum = temp[0];
        int i = 1;
        while (changeNum == '9' && i < temp.size())
            changeNum = temp[i++];
        string minNum, maxNum;
        while (num > 0) {
            char ld = num % 10 + '0';
            maxNum += (ld == changeNum) ? '9' : ld;
            minNum += (ld == temp[0]) ? '0' : ld;
            num /= 10;
        }
        reverse(minNum.begin(), minNum.end());
        reverse(maxNum.begin(), maxNum.end());
        return stoi(maxNum) - stoi(minNum);
    }
};