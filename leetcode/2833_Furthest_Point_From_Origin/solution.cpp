class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int x = 0, dash = 0;
        for(char ch: moves) {
            if(ch == 'L') x++;
            else if(ch == 'R') x--;
            else dash++;
        }
        return abs(x) + dash;
    }
};