class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string res = "Neither";
        if(length >= 10000 || width >= 10000|| height >= 10000 || 
            mass >= 10000 || 1LL*length*width*height >= 1000000000 ) {
                res = "Bulky";
        } 
        if (mass >= 100 && res == "Bulky") {
            res = "Both";
        }
        else if (mass >= 100) {
            res = "Heavy";
        }        
        return res;
    }
};