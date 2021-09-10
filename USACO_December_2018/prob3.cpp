#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

int n, k;
char grid[110][11];
int searched[110][11], zerofill[110][11];



void gravity() {
    for (int j = 0; j < 10; j++) {
        int cur = n-1;
        for (int i = n-1; i >= 0; i--) {
            if (grid[j][i] != '0') {
                grid[j][cur] = grid[j][i];
                cur--;
            }
        }
        for (int i = cur; i >=0; i--) grid[j][i] = '0';
    }
}

int floodfill(int x, int y, char c) {
    if (x < 0 || x > 9 || y < 0 || y >= n || grid[x][y] != c || searched[x][y] != 0) {
        return 0;
    }
    searched[x][y] = 1;
    return floodfill(x+1,y,c) + floodfill(x-1,y,c) + floodfill(x,y+1,c) + floodfill(x,y-1,c) + 1;
}

void floodzero(int x, int y, char c) {
    if (x < 0 || x > 9 || y < 0 || y >= n || grid[x][y] != c || zerofill[x][y] != 0) {
        return;
    }
    zerofill[x][y] = 1;
    grid[x][y] = '0';
    floodzero(x+1,y,c);
    floodzero(x-1,y,c);
    floodzero(x,y+1,c);
    floodzero(x,y-1,c);
    return;
}


int main() {
    
   // ifstream cin("mooyomooyo.in");
   // ofstream cout("mooyomooyo.out");
    
    cin >> n >> k;
    
    for  (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++)   {
            cin >> grid[j][i];
        }
    }
    
    bool ansFound = false;
    
    while (!ansFound) {
        ansFound = true;
        for (int i = 0; i < n; i++) {
            for (int j= 0; j < 10; j++) {
                searched[j][i] = 0;
                zerofill[j][i] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j= 0; j < 10; j++) {
                if (searched[j][i] == 0 && grid[j][i] != '0') {
                    int a = floodfill(j,i,grid[j][i]);
                    //cout << a << endl;
                    if (a >= k) {
                        ansFound = false;
                        floodzero(j,i,grid[j][i]);
                    }
                }
            }
        }
        gravity();
    }
    
    for  (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++)   {
            cout << grid[j][i];
        }
        cout << endl;
    }
    
}