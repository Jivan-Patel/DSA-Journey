class Solution {
public:
    string winningPlayer(int x, int y) {
        bool isAliceTrun = true;

        while(x >= 1 && y >= 4) {
            isAliceTrun = !isAliceTrun;
            x -= 1;
            y -= 4;
        }

        return isAliceTrun ? "Bob" : "Alice";
    }
};