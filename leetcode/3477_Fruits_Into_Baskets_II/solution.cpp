class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        for(int fruit : fruits) {
            bool isPlaced = false;
            for(int i = 0; i < baskets.size(); i++) {
                if(baskets[i] >= fruit) {
                    isPlaced = true;
                    baskets.erase(baskets.begin() + i);
                    break;
                }
            }
            if(!isPlaced) unplaced++;
        }
        return unplaced;
    }
};