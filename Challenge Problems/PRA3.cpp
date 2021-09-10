#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  
    ofstream cout ("hi.out");
    ifstream cin ("PRA3_1.in");

    int n, k, i, x;
    
    cin >> n;
    cout << n << endl;
    
    for (int a = 0; a < n; a++) {
        cin >> k >> i;
        cout << k << " " << i << endl;
        for (int b = 0; b < i; b++) {
            cin >> x;
            cout << x << " ";
        }
        cout << endl;
    }
}