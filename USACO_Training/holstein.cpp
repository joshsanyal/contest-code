/*
 ID: josh.sa1
 TASK: holstein
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

int numVit, req[30], numFeeds, feed[17][1010], ans = 1000, curVit[30];
bool curSol[17], sol[17];

void solve(int feedNum, int numAns) {
    bool stop = true;
    for (int i = 0; i < numVit; i++) {
        if (req[i] > curVit[i]) {
            stop = false;
        }
    }
    if (stop) {
        if (numAns < ans) {
            for (int i = 0; i < numFeeds; i++) {
                sol[i] = curSol[i];
            }
            ans = numAns;
        }
        if (numAns == ans) {
            bool better = true;
            for (int i = 0; i < numFeeds; i++) {
                if (curSol[i] == 1 && sol[i] == 0) {
                    better = true;
                    break;
                }
                else if (curSol[i] == 0 && sol[i] == 1) {
                    break;
                }
            }
            
            if (better) {
                for (int i = 0; i < numFeeds; i++) {
                    sol[i] = curSol[i];
                }
                ans = numAns;
            }
        }
        return;
    }
    if (feedNum == numFeeds) {
        return;
    }
    curSol[feedNum] = true;
    for (int i = 0; i < numVit; i++) {
        curVit[i] += feed[feedNum][i];
    }
    solve(feedNum + 1, numAns + 1);
    
    curSol[feedNum] = false;
    for (int i = 0; i < numVit; i++) {
        curVit[i] -= feed[feedNum][i];
    }
    solve(feedNum + 1, numAns);
}

int main() {
    
   ofstream cout ("holstein.out");
   ifstream cin ("holstein.in");
    
    cin >> numVit;
    for (int i = 0; i < numVit; i++) {
        cin >> req[i];
    }
    cin >> numFeeds;
    for (int i = 0; i < numFeeds; i++) {
        for (int j = 0; j < numVit; j++) {
            cin >> feed[i][j];
        }
    }
    
    solve(0,0);
    
    cout << ans;
    for (int i = 0; i < numFeeds; i++) {
        if (sol[i]) cout << " " << i + 1;
    }
    cout << endl;
}