class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int count0 = 0, count1 = 0;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == '0')
                    count0++;
                else
                    count1++;
                if (count0 > k && count1 > k)
                    break;
                ans++;
            }
        }
        return ans;
    }
};