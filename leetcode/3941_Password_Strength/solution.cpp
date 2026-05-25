class Solution {
public:
    int passwordStrength(string password) {
        vector<bool> visited(256, false);
        int points = 0;

        for(char ch : password) {
            unsigned char idx = ch;
            if(!visited[idx]) {
                visited[idx] = true;
                if(ch >= 'a' && ch <= 'z') points += 1;
                else if(ch >= 'A' && ch <= 'Z') points += 2;
                else if(ch >= '0' && ch <= '9') points += 3;
                else if(ch == '!' || ch == '@' || ch == '#' || ch == '$') points += 5;
            }
        }
        return points;
    }
};