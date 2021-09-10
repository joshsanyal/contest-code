#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int m, n, b, a[110], types;
double maximum = 0;

int main() {
    
    cin >> m >> n;
    
    for (int i = 0; i < m; i++) {
        cin >> b;
        a[b]++;
        if (a[b] > maximum) {
            maximum = a[b];
        }
        if (a[b] == 1) {
            types++;
        }
    }
    
    cout << ceil(maximum/n)*types*n - m << endl;
    
    
}