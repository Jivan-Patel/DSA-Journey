class Solution {
private:
    int minNumI(map<int, int> mp, int i) {
        int minim = INT_MAX;
        for (auto& min : mp) {
            minim = min.second;
            mp.erase(min.first);
            if(i < minim) break;
        }
        return minim;
    }

public:
    int firstStableIndex(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        int maxim = nums[0];
        int minI = minNumI(mp,-1);
        for (int i = 0; i < n; i++) {
            maxim = max(maxim, nums[i]);
            if (maxim - nums[minI] <= k)
                return i;
            if (minI == i) {
                minI = minNumI(mp,i);
            }
        }
        return -1;
    }
};