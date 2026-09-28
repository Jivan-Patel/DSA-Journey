#include <iostream>
using namespace std;
 
bool isExecute(const string& code) {
    for(char c : code) {
        if(c == 'H' || c == 'Q' || c == '9') {
            return true;
        }
    }
    return false;
}
 
int main() {
    string code;
    cin >> code;
 
    cout << (isExecute(code) ? "YES" : "NO");
 
    return 0;
}