class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowelTrack = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for(int i = 0; i < s.size() / 2; i++) 
            if(vowels.count(s[i]) > 0) vowelTrack++;

        for(int i = s.size() / 2; i < s.size(); i++) 
            if(vowels.count(s[i]) > 0) vowelTrack--;

        return !vowelTrack;
    }
};