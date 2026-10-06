#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> price(n);
 
    for(int i = 0; i < n; i++) 
        cin >> price[i];
 
    sort(price.begin(), price.end());
 
    int q;
    cin >> q;
 
    for(int i = 0; i < q; i++) {
        int money;
        cin >> money;
 
        if(money < price[0]) {
            cout << 0 << endl;
            continue;
        }
        else if(money >= price[n-1]) {
            cout << n << endl;
            continue;
        }
 
        int left = 0, right = n - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(price[mid] <= money) left = mid + 1;
            else right = mid;
        }
        
        cout << left << endl;
    }
 
    return 0;
}