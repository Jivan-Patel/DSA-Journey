#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int maxStreak = 1, curStreak = 1;
    int prevNum;
    cin >> prevNum;
 
    for(int i = 1; i < n; i++) {
        int num;
        cin >> num;
 
        if(prevNum > num) {
            maxStreak = max(maxStreak, curStreak);
            curStreak = 1;
        }
        else {
            curStreak++;
        }
 
        prevNum = num;
    }
    maxStreak = max(maxStreak, curStreak);
 
    cout << maxStreak;
 
    return 0;
}