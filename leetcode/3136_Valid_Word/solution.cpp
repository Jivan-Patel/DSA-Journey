class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;
        bool isVovel = false;
        bool isConsonent = false;
        set<char> vovel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (char ch : word) {
            if ((ch < 'a' || ch > 'z') && (ch < '0' || ch > '9') &&
                (ch < 'A' || ch > 'Z'))
                return false;
            else if (isVovel && isConsonent)
                continue;
            else if (vovel.count(ch))
                isVovel = true;
            else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                isConsonent = true;
        }
        return isVovel && isConsonent;
    }
};