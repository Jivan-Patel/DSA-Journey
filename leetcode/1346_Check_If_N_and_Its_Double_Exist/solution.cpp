class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> seen;
        for (int i = 0; i < arr.size(); i++) {
            if (seen.count(arr[i] * 2))
                return true;
            if (arr[i] % 2 == 0 && seen.count(arr[i] / 2))
                return true;
            seen.insert(arr[i]);
        }
        return false;
    }
};