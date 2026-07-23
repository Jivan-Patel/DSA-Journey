class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        for(int candy : candies) maxCandies = max(maxCandies, candy);

        int track = maxCandies - extraCandies;
        vector<bool> ans;

        for(int candy : candies) ans.push_back(candy >= track);

        return ans;
    }
};