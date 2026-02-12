class Solution {
public:
    string defangIPaddr(string address) {
    string res = "";
    int len = address.size();
    for(int i = 0; i < len; i++) {
        if(address[i] == '.') res+="[.]";
        else res+=address[i];
    }
    return res;        
    }
};