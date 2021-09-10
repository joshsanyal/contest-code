/*
 ID: josh.sa1
 TASK: castle
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int m, n, a, largestRoom = 0, numRooms = 0, roomSize[55][55], sizes[2510], roomX, roomY, maxSize = 0, roomSizes[55][55];
bool north[55][55], west[55][55], east[55][55], south[55][55], visited[55][55];
char direction;

int flood(int x, int y, int counter) {
    
    int sum = 1;
    roomSize[x][y] = counter;
    
    if(!north[x][y] && !visited[x-1][y]) {
        visited[x-1][y] = true;
        sum += flood(x-1,y,counter);
    }
    if(!south[x][y] && !visited[x+1][y]) {
        visited[x+1][y] = true;
        sum += flood(x+1,y,counter);
    }
    if(!east[x][y] && !visited[x][y+1]) {
        visited[x][y+1] = true;
        sum += flood(x,y+1,counter);
    }
    if(!west[x][y] && !visited[x][y-1]) {
        visited[x][y-1] = true;
        sum += flood(x,y-1,counter);
    }
    
    return sum;
}

int main() {
    
    ofstream cout ("castle.out");
    ifstream cin ("castle.in");
    
    cin >> m >> n;
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            if (a >= 8) {
                south[i][j] = true;
                a -= 8;
            }
            if (a >= 4) {
                east[i][j] = true;
                a -= 4;
            }
            if (a >= 2) {
                north[i][j] = true;
                a -= 2;
            }
            if (a >= 1) {
                west[i][j] = true;
            }
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                numRooms++;
                sizes[numRooms] = flood(i,j,numRooms);
                if (sizes[numRooms] > largestRoom) {
                    largestRoom = sizes[numRooms];
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            roomSizes[i][j] = sizes[roomSize[i][j]];
        }
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = n-1; i >= 0; i--) {
            if (i != 0 && north[i][j] && roomSize[i][j] != roomSize[i-1][j] && roomSizes[i][j] + roomSizes[i-1][j] > maxSize) {
                direction = 'N';
                roomX = i + 1;
                roomY = j + 1;
                maxSize = roomSizes[i][j] + roomSizes[i-1][j];
            }
            if (j != m-1 && east[i][j] && roomSize[i][j] != roomSize[i][j+1] && roomSizes[i][j] + roomSizes[i][j+1] > maxSize) {
                direction = 'E';
                roomX = i + 1;
                roomY = j + 1;
                maxSize = roomSizes[i][j] + roomSizes[i][j+1];
            }
        }
    }
    
    cout << numRooms << endl << largestRoom << endl << maxSize << endl << roomX << " " << roomY << " " << direction << endl;

    
}