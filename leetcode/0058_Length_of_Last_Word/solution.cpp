class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastI = s.size() - 1;

        while(lastI >= 0 && s[lastI] == ' ') lastI--;

        int startI = lastI;

        while(startI >=0 && s[startI] != ' ') startI--;


        return lastI - startI;
    }
};