#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool distinct(int n) {
    int a, b, c, d;
    a = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    c = n % 10;
    d = n / 10;
    
    if (a != b && a != c && a != d && b != c && b != d && c != d) {
        return true;
    }
    return false;
}

int n, e;

int main() {
    
  //  ofstream cout ("PRA1.out");
  //  ifstream cin ("PRA1.in");
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        bool ansFound = false;
        cin >> e;
        while (!ansFound) {
            e++;
            if (distinct(e)) {
                ansFound = true;
            }
        }
        cout << e << endl;
    }
}

