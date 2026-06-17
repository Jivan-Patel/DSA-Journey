class Solution {
public:
    string clearDigits(string s) {
        string result = "";

        for(char ch : s) {
            if(isalpha(ch)) result += ch;
            else result.pop_back();
        }

        return result;
    }
};