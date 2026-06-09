class Solution {
public:
    bool consecutiveSetBits(int n) {
        string binary = "";
        bool isPair = false;
        while(n > 0) {
            if(!binary.empty() && binary.back() == '1' && n % 2 == 1) {
                if(isPair) return false;
                isPair = true;
            }
            binary += to_string(n % 2);
            n /= 2;
        }
        return isPair;
    }
};