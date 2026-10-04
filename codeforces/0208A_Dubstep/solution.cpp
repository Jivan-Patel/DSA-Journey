#include <iostream>
using namespace std;
 
int main() {
    string dubstep = "";
    cin >> dubstep;
 
    string lyrics = "";
 
    int i = 0;
    while(i < dubstep.size()) {
        string subStr = dubstep.substr(i,3);
        if(subStr == "WUB") {
            if(lyrics != "" && lyrics.back() != ' ') {
                lyrics += ' ';
            }
            i += 3;
        }
        else {
            lyrics += dubstep[i];
            i += 1;
        }
    }
 
    if(!lyrics.empty() && lyrics.back() == ' ') {
        lyrics.pop_back();
    }
 
    cout << lyrics;
 
    return 0;
}