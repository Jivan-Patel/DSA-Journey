#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n , m;
    cin >> n >> m;
    
    int puzzle[m];
    
    for(int i = 0; i < m; i++) {
        cin >> puzzle[i];
    }
 
    sort(puzzle, puzzle + m);
 
    int i = 0, j = n - 1;
    int minDifference = puzzle[j++] - puzzle[i++];
 
 
    while(j < m) {
        minDifference = min(puzzle[j++] - puzzle[i++], minDifference);
    }
 
    cout << minDifference;
 
    return 0;
}