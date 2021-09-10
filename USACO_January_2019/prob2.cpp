#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int n, maxArea, minPeri = 10000000;
char grid[1010][1010];
bool searched[1010][1010];
bool psearched[1010][1010];

int floodfill(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >=n || searched[x][y] == true || grid[x][y] == '.') return 0;
    searched[x][y] = true;
    return floodfill(x+1, y) + floodfill(x-1, y) + floodfill(x, y+1) + floodfill(x, y-1) + 1;
}

int perimeter(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == '.') {
        return 1;
    }
    if (psearched[x][y] == true) return 0;
    psearched[x][y] = true;
    return perimeter(x+1, y) + perimeter(x-1, y) + perimeter(x, y+1) + perimeter(x, y-1);
}

int main() {
    
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[j][i];
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (searched[j][i] == false && grid[j][i] == '#') {
                int area = floodfill(j, i);
                if (area > maxArea) {
                    maxArea = area;
                    minPeri = perimeter(j, i);
                }
                else if (area == maxArea) {
                    int peri = perimeter(j, i);
                    if (peri < minPeri) {
                        maxArea = area;
                        minPeri = peri;
                    }
                    
                }
            }
        }
    }
    
    cout << maxArea << " " << minPeri << endl;
    
}