class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n == 1) return 1;
        else if(n == 2) return 1;
        int tl = 0, sl = 1, l = 1;
        int i = 3;

        while(i <= n) {
            int current = tl + sl + l;
            tl = sl;
            sl = l;
            l = current;
            i++;
        }

        return l;
    }
};