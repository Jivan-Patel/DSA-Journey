class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int minI = -1;
        
        for(int i = n - 1; i >= 0; i--) {
            if(capacity[i] >= itemSize) {
                if((minI == -1) || capacity[minI] >= capacity[i]) minI = i;
            }
        }

        return minI;
    }
};