class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map <int, vector<char>> letter = {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };
        vector<vector<char>> temp;
        vector<string> res;
        for(int i = 0; i < digits.size(); i++) {
            temp.push_back(letter[digits[i]]);
        }
        for(int i1 = 0; i1 < temp.size(); i1++) { 
            for(int j1 = 0; j1 < temp[i1].size(); j1++) {
                if(digits.size() == 1) {
                    string r;
                    r += temp[i1][j1];                    
                    res.push_back(r);
                    continue;
                }
                for(int i2 = i1 + 1; i2 < temp.size(); i2++) { 
                    for(int j2 = 0; j2 < temp[i2].size(); j2++) {
                        if(digits.size() == 2) {
                            string r;
                            r += temp[i1][j1];
                            r += temp[i2][j2];
                            res.push_back(r);
                            continue;
                        }
                        for(int i3 = i2 + 1; i3 < temp.size(); i3++) { 
                            for(int j3 = 0; j3 < temp[i3].size(); j3++) {
                                if(digits.size() == 3) {
                                    string r;
                                    r += temp[i1][j1];
                                    r += temp[i2][j2];
                                    r += temp[i3][j3];
                                    res.push_back(r);
                                    continue;
                                }
                                for(int i4 = i3 + 1; i4 < temp.size(); i4++) { 
                                    for(int j4 = 0; j4 < temp[i4].size(); j4++) {
                                        if(digits.size() == 4) {
                                            string r;
                                            r += temp[i1][j1];
                                            r += temp[i2][j2];
                                            r += temp[i3][j3];
                                            r += temp[i4][j4];
                                            res.push_back(r);
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
            }
        }
        return res;
    }
};