class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.size();
        string halfStr = "", res = "";
        vector<int> freq(26, 0);

        for (int i = 0; i < len / 2; i++) freq[s[i] - 'a']++;

        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                halfStr += i + 'a';
                freq[i]--;
            }
        }

        res += halfStr;
        reverse(halfStr.begin(), halfStr.end());

        if(len % 2 == 1) res += s[len / 2];

        res += halfStr;

        return res;
    }
};