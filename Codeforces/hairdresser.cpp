#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
long long l, lengths[100100];
bool rn = false;

int main() {
    
    cin >> n >> m >> l;
    
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
        if (!rn && lengths[i] > l) {
            ans++;
            rn = true;
        }
        if (lengths[i] <= l) {
            rn = false;
        }
    }
    
    int a, b;
    long long c;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (a == 0) {
            cout << ans << endl;
        }
        else {
            cin >> b >> c;
            b--;
            if (lengths[b] <= l && (lengths[b] + c) > l) {
                if (b == 0) {
                    if (lengths[b+1] <= l) {
                        ans++;
                    }
                }
                else if (b == n - 1) {
                    if (lengths[b-1] <= l) {
                        ans++;
                    }
                }
                else {
                    if (lengths[b-1] <= l && lengths[b+1] <= l) {
                        ans++;
                    }
                    else if (lengths[b-1] > l && lengths[b+1] > l) {
                        ans--;
                    }
                }
            }
            lengths[b] += c;
        }
    }
    
    
}