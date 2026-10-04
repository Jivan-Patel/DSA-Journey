#include <iostream>
#include<algorithm>
using namespace std;
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;
 
    int maxVal = max({
        a + b + c,
        a * b * c,
        (a + b) * c,
        a * (b + c),
    });
 
    cout << maxVal;
 
    return 0;
}