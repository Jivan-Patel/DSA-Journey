class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if (n == 1) return ans;

        for(int i = 2; i <= n; i++) {
            int count = 1;
            string temp = "";

            for(int j = 1; j <= ans.size(); j++) {
                if(j != ans.size() && ans[j] == ans[j-1]) count++;
                else {
                    temp += to_string(count);
                    temp += ans[j-1];
                    count = 1;
                }
            }
            ans = temp;
        }

        return ans;
    }
};