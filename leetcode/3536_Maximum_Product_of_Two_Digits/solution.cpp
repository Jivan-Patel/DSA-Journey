class Solution {
public:
    int maxProduct(int n) {
        string temp;
        while(n > 0) {
            temp += n%10;
            n/=10;
        }
        int m1 = -1;
        int m2 = -1;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] >= m1) {
                m2 = m1;
                m1 = temp[i];
            } else if (temp[i] > m2) {
                m2 = temp[i];
            }
        }
        return m1 * m2;
    }
};