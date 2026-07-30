class Solution {
public:
    int minimumPushes(string word) {
        int len = word.size();
        if(len <= 8) return len;
        else if(len <= 16) return 8 + (len-8) * 2;
        else if(len <= 24) return 24 + (len-16) * 3;
        else return 48 + (len-24) * 4;
    }
};