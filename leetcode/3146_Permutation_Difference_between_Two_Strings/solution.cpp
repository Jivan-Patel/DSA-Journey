class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum = 0;
        vector<int> tTrack(26, 0);

        for(int i = 0; i < t.size(); i++) tTrack[t[i] - 'a'] = i;
        
        for(int i = 0; i < s.size(); i++) sum += abs(i - tTrack[s[i] - 'a']);

        return sum;
    }
};