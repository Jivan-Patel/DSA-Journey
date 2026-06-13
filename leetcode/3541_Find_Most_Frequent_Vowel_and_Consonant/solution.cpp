class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int vovelMax = 0, consoMax = 0;
        for (char c : s) {
            freq[c - 'a']++;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vovelMax = max(vovelMax, freq[c - 'a']);
            }
            else {
                consoMax = max(consoMax, freq[c - 'a']);
            }
        }
        return vovelMax + consoMax;
    }
};