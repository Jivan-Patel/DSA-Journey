class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int flag = 0;
        for (int i = 0; i < arr.size(); i++) {
            bool isUnique = true;
            for (int j = 0; j < arr.size(); j++) {
                if (arr[i] == arr[j] && i != j) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                flag++;
                if (flag == k)
                    return arr[i];
            }
        }
        return "";
    }
};