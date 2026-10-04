#include <iostream>
#include <cctype>
using namespace std;
 
int main() {
    string word;
    cin >> word;
 
    int upperLetter = 0;
 
    for(int i = 1; i < word.size(); i++) {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            upperLetter++;
        }
        else break;
    }
 
    if(upperLetter < word.size() - 1) {
        cout << word;
        return 0;
    }
 
    string reqWord = "";
    reqWord += (word[0] >= 'A' && word[0] <= 'Z') ? tolower(word[0]) : toupper(word[0]);
 
    for(int i = 1; i < word.size(); i++) {
        reqWord += tolower(word[i]);
    }
 
    cout << reqWord;
 
    return 0;
}