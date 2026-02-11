class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        int l = details.size();
        for (int i = 0; i < l; i++) {
            if (details[i][11] > '6')
                count++;
            else if (details[i][11] == '6' && details[i][12] > '0')
                count++;
        }
        return count;
    }
};