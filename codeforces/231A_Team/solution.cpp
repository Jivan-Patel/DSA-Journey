#include <iostream>
using namespace std;
int main() {
    int n, a, b, c, count = 0;
    if (cin >> n) {
        while (n--) {
            cin >> a >> b >> c;
            if (a + b + c >= 2) count++;
        }
        cout << count << endl;
    }
    return 0;
}