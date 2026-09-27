#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
    string s;
    if (cin >> s) {
        unordered_set<char> chars;
        for (char c : s) chars.insert(c);
        if (chars.size() % 2 == 0) cout << "CHAT WITH HER!" << endl;
        else cout << "IGNORE HIM!" << endl;
    }
    return 0;
}