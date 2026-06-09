class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack <bool> depth;
        for(string log : logs) {
            if(log == "../") {
                if(!depth.empty()) depth.pop();
            }
            else if(log != "./") depth.push(1);
        }
        return depth.size();
    }
};