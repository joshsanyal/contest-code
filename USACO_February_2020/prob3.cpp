#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, a, b;
int connections[100100];

int main() {

    ifstream cin("deleg.in");
    ofstream cout("deleg.out");

    cin >> n;
    for (int i = 0; i < n-1; i++) {
    	cin >> a >> b;
    	connections[a]++;
    	connections[b]++;
    }

    int odds = 0;
    for (int i = 1; i <= n; i++) {
    	if (connections[i] % 2 == 1) odds++;
    }

    for (int i = 1; i < n; i++) {
    	if ((n-1) % i == 0 && i <= (n-1)*2/odds) cout << 1;
    	else cout << 0;
    }
    cout << endl;
    
}