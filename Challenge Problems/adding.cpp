#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int n, a, b;

int main() {
    
   // ofstream cout ("PRB1.out");
   // ifstream cin ("PRB1.in");
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a + b << endl;
    }
}

