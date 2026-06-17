class Solution {
public:
    int minLength(string s) {
        bool flag = true;

        while(flag) {
            flag = false;
            auto it = s.find("AB");
            if(it != -1) {
                s.erase(it, 2);
                flag = true;
            }

            it = s.find("CD");
            if(it != -1) {
                s.erase(it, 2);
                flag = true;
            }
        }

        return s.size();
    }
};