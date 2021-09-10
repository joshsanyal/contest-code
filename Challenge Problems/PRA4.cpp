#include <algorithm>
#include <iostream>

using namespace std;

int n, dp[50500];
pair<long long, long long> cow[50500];

int main() {
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        long long s, e;
        cin >> s >> e;
        cow[i] = make_pair(e,s);
    }
    sort(cow, cow + n);
    
    dp[1] = 1;
    
    for (int i = 2; i < n; i++) {
        int l = 0, r = i-1;
        while (l < r-1) {
            int m = (l + r)/2;
            if (cow[m].first <= cow[i].second) {
                l = m;
            }
            else {
                r = m;
            }
        }
        dp[i] = max(dp[i-1], dp[r] + 1);
    }
    
    cout << dp[n-1] << endl;
}