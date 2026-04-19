class Solution {
private:
    int minIdx(vector<int> nums, int i) {
        int minim = i;
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[minim] > nums[j])
                minim = j;
        }
        return minim;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxim = nums[0];
        int minI = minIdx(nums, 0);
        
        for(int i = 0; i < n; i++) {
            maxim = max(maxim, nums[i]);
            if(maxim - nums[minI] <= k) return i;
            if(minI == i) minI = minIdx(nums, i+1);
        }
        return -1;
    }
};