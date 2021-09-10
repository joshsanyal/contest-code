#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

typedef long long ll;

int T, z;

int main() {
    
    //ofstream cout ("PRB3.out");
    //ifstream cin ("PRB3.in");

    cin >> T;
    
    for(int t = 0;t < T;t++) {
        priority_queue<ll, vector<ll>, greater<ll> > q;
        int N;
        
        cin >> z >> N;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            q.push(x);
        }
        
        ll cost = 0;
        for (;;) {
            ll a = q.top();
            q.pop();
            if (q.empty()) break;
            ll b = q.top();
            q.pop();
            cost += a + b;
            q.push(a + b);
        }
        cout << cost << endl;
    }
    return 0;
}