#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, h, ans = 100000000;
pair<int, int> package[110]; // amount (first), cost (second)
int dp[50500];


int main() {
    
    cin >> n >> h;
    
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        package[i] = make_pair(a, b);
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                dp[package[j].first] = package[j].second;
            }
            else if (dp[i] != 0) {
                if (dp[i + package[j].first] == 0) {
                    dp[i + package[j].first] = dp[i] + package[j].second;
                }
                else {
                    dp[i + package[j].first] = min(dp[i + package[j].first], dp[i] + package[j].second);
                }
            }
        }
    }
    
    
    for (int i = h; i <= h + 5000; i++) {
        if (dp[i] != 0) ans = min(ans, dp[i]);
    }
    cout << ans << endl;
}