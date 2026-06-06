class Solution {
public:
    string removeDuplicates(string s, int k) {
        int count = 0;
        string res = "";

        for (char ch : s) {
            if (!res.empty()) {
                if(res.back() == ch) count++;
                else count = 1;
                res.push_back(ch);

                if(count == k) {
                    res.erase(res.end() - k, res.end());
                    count = 1;
                    if(!res.empty()) {
                        int i = res.size() - 2;
                        while(i >= 0 && res[i] == res[i+1]) {
                            count++;
                            i--;
                        }
                    }
                }                
            }
            else {
                res.push_back(ch);
                count = 1;
            }
        }

        return res;
    }
};