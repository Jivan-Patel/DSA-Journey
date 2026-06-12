class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int oddCount = 0;
        for(int n : nums) oddCount += n % 2;
        int evenCount = nums.size() - oddCount;

        vector<int> ans;

        for(int num : nums) {
            if(num % 2 == 0) {
                evenCount--;
                ans.push_back(oddCount);
            }
            else {
                oddCount--;
                ans.push_back(evenCount);
            }
        }
        return ans;
    }
};