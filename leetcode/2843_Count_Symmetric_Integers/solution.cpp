class Solution {
private:
    bool checkDigit(int num) {
        vector<int> digitArr;
        while (num > 0) {
            digitArr.push_back(num % 10);
            num /= 10;
        }
        int j = digitArr.size();
        if (digitArr.size() % 2 == 1)
            return false;
        int i = 0;
        j--;
        int leftSum = 0;
        int rightSum = 0;
        while (i < j) {
            leftSum += digitArr[i];
            rightSum += digitArr[j];
            i++;
            j--;
        }
        return leftSum == rightSum;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (checkDigit(i))
                count++;
        }
        return count;
    }
};