class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word) freq[c - 'a']++;
        sort(freq.begin(), freq.end());

        int press = 0, count = 1;

        for (int i = freq.size() - 1; i >= 0; i--) {
            if(freq[i] == 0) break;

            if(count <= 8) press += freq[i];
            else if(count <= 16) press += freq[i]*2;
            else if(count <= 24) press += freq[i]*3;
            else press += freq[i]*4;
            count++;
        }

        return press;
    }
};