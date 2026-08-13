class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxProd = 0, n = words.size();
        vector<bool> freq(n * 26, false);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                freq[i * 26 + words[i][j] - 'a'] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool isUnique = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[i * 26 + k] && freq[j * 26 + k]) {
                        isUnique = false;
                        break;
                    }
                }
                if (isUnique) {
                    int prod = words[i].size() * words[j].size();
                    maxProd = max(maxProd, prod);
                }
            }
        }

        return maxProd;
    }
};