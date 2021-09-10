#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int s, n, fir[1010], sec[1010];
bool possible = false;

int main() {
    
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        cin >> fir[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> sec[i];
    }
    
    if (fir[0] == 1) {
        if (fir[s-1] == 1) {
            possible = true;
        }
        else if (sec[s-1] == 1){
            for (int i = s; i < n; i++) {
                if (fir[i] == 1 && sec[i] == 1) {
                    possible = true;
                }
            }
        }
        
    }
    
    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
}