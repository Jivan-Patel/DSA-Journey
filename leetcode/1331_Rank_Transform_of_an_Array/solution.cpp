class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> sortedNum;
        int rank = 1;
        vector<int> res;

        for(int i = 0; i < arr.size(); i++) sortedNum[arr[i]] = 0;
        for(auto& [n, count] : sortedNum) count = rank++;
        for(int i = 0; i < arr.size(); i++) res.push_back(sortedNum[arr[i]]);

        return res;        
    }
};