#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int s, n;
    cin >> s >> n;
 
    vector<vector<int>> arr(n, vector<int>(2));
 
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
 
    sort(arr.begin(), arr.end());
 
    for(int i = 0; i < n; i++) {
        if(arr[i][0] >= s) {
            cout << "NO";
            return 0;
        }
        s += arr[i][1];
    }
 
    cout << "YES";
 
    return 0;
}