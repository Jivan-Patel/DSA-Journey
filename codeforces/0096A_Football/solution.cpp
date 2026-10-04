#include <iostream>
using namespace std;
 
bool isDangerous(string s) {
    int n = s.size();
    if(n < 7) return false;
 
    int curStreak = 1;
 
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            curStreak++;
            if(curStreak >= 7) return true;
        }
        else {
            curStreak = 1;
        }
    }
 
    return false;
}
 
int main() {
    string s;
    cin >> s;
 
    if(isDangerous(s)) cout << "YES";
    else cout << "NO";    
 
    return 0;
}