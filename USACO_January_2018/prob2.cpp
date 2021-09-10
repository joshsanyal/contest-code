#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>


using namespace std;

long long tiles, boots;
long long tile[1000];
pair<long long, long long> boot[1000];
long long a, b;
long long currentTile = 0, currentBoot = 0;

int main() {
    
    
    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    
    
    cin >> tiles >> boots;
    
    for (int i = 0; i < tiles; i++) {
        cin >> tile[i];
    }
    for (int i = 0; i < boots; i++) {
        cin >> a >> b;
        boot[i] = make_pair(a,b);
    }
    
    while (currentTile != tiles - 1) {
        
        long long oldTile = currentTile;
        int i;
        
        int hi = currentTile + boot[currentBoot].second;
        if (hi > tiles - 1) {
            hi = tiles - 1;
        }
        
        for (i = hi; i > currentTile; i--) {
            if (tile[i] <= boot[currentBoot].first) {
                currentTile = i;
                break;
            }
        }
        
        if (oldTile == i) {
            currentBoot++;
        }
    }
    
    cout << currentBoot << endl;
    
}