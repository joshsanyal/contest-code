#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

int n, m, c, t[101000], d[101000], bigDiff[101000], order[101000], start;

int main() {
    
    ifstream cin("convention.in");
    ofstream cout("convention.out");
    
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t,t+n);
    
    for (int i = 0; i < n - 1; i++) {
        d[i] = t[i+1] - t[i];
        bigDiff[i] = d[i];
    }
    
    sort(bigDiff, bigDiff + n - 1, greater<int>());

    cout << bigDiff[m-2] << endl;
    
//   for (int i = n - 2; i >= 0; i--) {
//        order[bigDiff[i]] = i+1;
//    }
//    
//    start = 0;
//    while (m > 1 && start <= n - c) {
//        int max = 0, index = 0;
//        for (int i = start + n/m - 1; i < start + c; i++) {
//            if (d[i] > max) {
//                max = d[i];
//                index = i;
//            }
//        }
//        if (order[max] <= m) {
//            d[index] = 0;
//            start = index + 1;
//        }
//        else {
//            d[start + c - 1] = 0;
//            start = start + c;
//        }
//        m--;
//    }
//  
//    sort(d, d + n - 1, greater<int>());
//        
//    cout << d[m-1] << endl;
    
}