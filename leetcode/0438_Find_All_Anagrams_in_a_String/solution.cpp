class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0;
        vector<int> ans;
        int len = p.size();
        vector<int> freq(26, 0);
        for(char ch : p) freq[ch - 'a']++;

        for(int i = 0; i + len - 1 < s.size(); i++) {
            vector<int> currentFreq(26, 0);
            for(int j = 0; j < len; j++) currentFreq[s[i+j] - 'a']++;
            bool isAnagram = true;
            for(int j = 0; j < 26; j++) {
                if(freq[j] != currentFreq[j]) {
                    isAnagram = false;
                    break;
                }
            }
            if(isAnagram) ans.push_back(i);
        }

        return ans;
    }
};