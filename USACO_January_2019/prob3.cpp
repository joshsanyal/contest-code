#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int n, ans;
pair<long long, long long> point[101000];
long long m = 0;

int main() {
    ifstream cin("mountains.in");
    ofstream cout("mountains.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        point[i] = make_pair(y-x,y+x);
    }
    sort (point, point + n);
    for (int i = n - 1; i >= 0; i--) {
        if (point[i].second > m) {
            m = point[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}