class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int j1 = version1.size();
        int j2 = version2.size();

        while(i1 < j1 || i2 < j2) {
            int n1 = 0, n2 = 0;

            while(i1 < j1 && version1[i1] != '.') {
                n1 = (n1 * 10) + (version1[i1] - '0');
                i1++;
            }
            
            while(i2 < j2 && version2[i2] != '.') {
                n2 = (n2 * 10) + (version2[i2] - '0');
                i2++;
            }

            if(n1 > n2) return 1;
            else if(n2 > n1) return -1;

            i1++;
            i2++;
        }
        return 0;        
    }
};