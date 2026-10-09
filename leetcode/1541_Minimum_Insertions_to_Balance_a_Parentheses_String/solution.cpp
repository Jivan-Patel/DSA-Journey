class Solution {
public:
    int minInsertions(string s) {
        int insertionCount = 0, open = 0;
        int n = s.size();
        int i = 0;

        while(i < n) {
            if(s[i] == '(') open++;
            else if(i + 1 < n && s[i+1] == ')') {
                i++;
                if(open > 0) open--;
                else insertionCount++;
            }
            else {
                insertionCount++;
                if(open > 0) open--;
                else insertionCount++;
            }
            i++;        
        }

        return insertionCount + open * 2;
    }
};