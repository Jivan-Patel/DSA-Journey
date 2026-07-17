class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelC = 0;
        int low = 0, high = k;
        unordered_set<char> vowels = {'a','e','i','o','u'};
        for(int i = 0; i < k; i++) {
            if(vowels.count(s[i])) vowelC++;
        }
        int maxvowels = vowelC;
        
        while(high < s.size()) {
            if(vowels.count(s[low]) > 0) vowelC--;
            if(vowels.count(s[high]) > 0) {
                vowelC++;
                maxvowels = max(maxvowels, vowelC);
            }
            high++; low++;
        }

        return maxvowels;
    }
};