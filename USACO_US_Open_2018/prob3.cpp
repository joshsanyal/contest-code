#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n, oneBest;
long grid[255][255];
bool checked[255][255] = {false};

int solve(int row, int col, int id) {
    if (row < 0 || row > n-1 || col < 0 || row > n-1) {
        return 0;
    }
    if (grid[row][col] != id) {
        return 0;
    }
    if (checked[row][col] == true) {
        return 0;
    }
    checked[row][col] = true;
    
    return solve(row + 1, col, id) + solve(row - 1, col, id) + solve(row, col + 1, id) + solve(row, col - 1, id) + 1;
}


int main() {
    
    
    //ifstream cin("multimoo.in");
    //ofstream cout("multimoo.out");
    
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (checked[i][j] == false) {
                oneBest = max(oneBest, solve(i,j,grid[i][j]));
            }
        }
    }
    
    cout << oneBest << endl;
    
}