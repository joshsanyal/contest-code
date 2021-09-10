#include <iostream>
#include <cmath>

using namespace std;

int n, cubes, cube[11][6], nums[1000] = {0};
int cur[11], power, digits[11], counter;
int chosen[11], visited[11], counter2, num;

void perm(int x, int numDigits) {
    if (x == numDigits) {
        counter2 = 0, num = 0;
        for (int i=0; i<numDigits; i++) {
            num += digits[chosen[i]] * pow (10,counter2);
            counter2++;
        }
        nums[num] = 1;
        return;
    }
    
    for (chosen[x] = 0; chosen[x]<6; chosen[x]++) {
        if (visited[chosen[x]] == 0) {
            visited[chosen[x]] = 1;
            perm(x+1,numDigits);
            visited[chosen[x]] = 0;
        }
    }
}

void solve(int i) {
    if (i == cubes) {
        counter = 0;
        for (int a = 0; a<cubes; a++) {
            if (cur[a] != 6) {
                digits[counter] = cube[a][cur[a]];
                counter++;
            }
        }
        perm(0,counter);
        return;
    }
    
    for (cur[i] = 0; cur[i]<7; cur[i]++) {
        solve(i+1);
    }
}

int main() {
    
    cin >> n;
    
    for (int i = 0; i<n; i++) {
        cin >> cubes;
        for (int k = 0; k<cubes; k++) {
            for (int j = 0; j < 6; j++) {
                cin >> cube[k][j];
            }
        }
        
        
        solve(0);
        
        
        bool found = false;
        for (int i = 0; i<1000; i++) {
            if (nums[i] == 0 && !found) {
                cout << i-1 << endl;
                found = true;
            }
            nums[i] = 0;
        }
        
        
    }
    
}