#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int one = 0;
    bool isTwo = false;
    int cab = 0;
 
    for(int i = 0; i < n; i++) {
        int children;
        cin >> children;
 
        if(children == 4) {
            cab++;
        }
        else if(children == 3) {
            cab++;
            one--;
        }
        else if(children == 1) {
            one++;
        }
        else if(isTwo) {
            cab++;
            isTwo = false;
        }
        else {
            isTwo = true;
        }
    }
 
    if(isTwo) {
        cab++;
        one -= 2;
    }
 
    if(one > 0) {
        cab += one / 4;
        if(one % 4 != 0) {
            cab++;
        }
    }
 
    cout << cab;
 
    return 0;
}