class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> track;
        for(int i = 0; i < nums.size(); i++) {
            track[nums[i]].push_back(i);
        }

        int count = 0;
        for(auto& pair : track) {
            if(pair.second.size() >= 3) {
                count++;
                int diff = pair.second[1] - pair.second[0];
                for(int i = 2; i < pair.second.size(); i++) {
                    if(pair.second[i] - pair.second[i-1] != diff) {
                        count--;
                        break;
                    }
                }
                
            }
        }

        return count;
    }
};