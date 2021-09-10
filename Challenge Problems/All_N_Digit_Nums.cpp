#include <iostream>
#include <vector>

using namespace std;

int grid[10][10];
bool used[99999999] = {false};
int answer = 0;

void gen (int x, int y, int jumps, int num) {
    if (jumps == 6) {
        if (!used[num]) {
            answer++;
            used[num] = true;
        }
        return;
    }
    
    if (x < 4) {
        gen (x+1, y, jumps+1, num * 10 + grid[x][y]);
    }
    if (y < 4) {
        gen (x, y+1, jumps+1, num * 10 + grid[x][y]);
    }
    if (x > 0) {
        gen (x-1, y, jumps+1, num * 10 + grid[x][y]);
    }
    if (y > 0) {
        gen (x, y-1, jumps+1, num * 10 + grid[x][y]);
    }
}

int main() {
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            gen(i, j, 0, 0);
        }
    }
    
    cout << answer << endl;
    
}