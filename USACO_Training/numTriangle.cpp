/*
 ID: josh.sa1
 TASK: numtri
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int rows;
int tree[1010][1010];

int opt[1010][1010];

int main() {
    
    ofstream cout ("numtri.out");
    ifstream cin ("numtri.in");
    
    cin >> rows;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tree[i][j];
        }
    }
    
    for (int i = rows-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (i == (rows - 2)) {
                opt[i][j] = tree[i][j] + max(tree[i+1][j],tree[i+1][j+1]);
            }
            else {
                opt[i][j] = tree[i][j] + max(opt[i+1][j],opt[i+1][j+1]);
            }
        }
    }
    
    cout << opt[0][0] << endl;
    
}