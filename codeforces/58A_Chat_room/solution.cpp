#include <iostream>
using namespace std;
 
int main() {
    string message;
    cin >> message;
 
    string hello = "hello";
    int i = 0;
 
    for(char c: message) {
        if(c == hello[i]) {
            i++;
            if(i > 5) break;
        }
    }
    
    if(i == 5) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
 
    return 0;
}