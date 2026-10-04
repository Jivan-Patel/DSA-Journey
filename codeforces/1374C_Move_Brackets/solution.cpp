#include <iostream>
using namespace std;
 
void moves(string brackets) {
    int open = 0, move = 0;
    
    for(char c : brackets) {
        if(c == '(') open++;
        else if(open > 0) open--;
        else move++;
    }
 
    cout << move << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string brackets;
        cin >> brackets; 
 
        moves(brackets);
    }
 
 
    return 0;
}