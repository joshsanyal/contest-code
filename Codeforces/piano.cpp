#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long n, key[200100], rep[200100], inc[200100], seq[200100], ans[200100];
bool pos = true;
long streak = 0, curIndex = 0, curChange = -1;

int main() {
    
    cin >> n;
    
   
    for (int i = 0; i < n; i++) {
        cin >> key[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            if (key[i] == key[i+1]) {
                inc[i] = 0;
            }
            else if (key[i] > key[i+1]) {
                inc[i] = -1;
            }
            else {
                inc[i] = 1;
            }
            
        }
        
        if (i == 0) {
            rep[curIndex] = streak;
            streak = 1;
            curIndex = i;
        }
        if (i > 0) {
            if (key[i] == key[i-1]) {
                streak++;
            }
            else {
                rep[curIndex] = streak;
                streak = 1;
                curIndex = i;
            }
        }
        
        if (i == n - 1) {
            rep[curIndex] = streak;
        }
    }

    curIndex = 0, streak = 0;
    for (int i = 0; i < n; i++) {
        if (curChange != inc[i]) {
            seq[curIndex] = streak;
            curChange = inc[i];
            curIndex = i;
            streak = curChange;
        }
        else if (curChange == 1) {
            streak++;
            if (streak >= 5) {
                pos = false;
            }
        }
        else if (curChange == -1) {
            streak--;
            if (streak <= -5) {
                pos = false;
            }
        }
        if (i == n - 1) {
            seq[curIndex] = streak;
        }
    }
    
    long repeat = 0;
    
    
    if (pos) {
        for (int i = 0; i < n; i++) {
            if (seq[i] != 0) {
                if (seq[i] > 0) {
                    ans[i] = 5 - seq[i];
                }
                else {
                    ans[i] = 1 - seq[i];
                }
            }
            else {
                if (inc[i-1] == 1) {
                    ans[i] = ans[i-1] + 1;
                }
                else if (inc[i-1] == -1) {
                    ans[i] = ans[i-1] - 1;
                }
                else {
                    if (rep[i] > 1) {
                        repeat = rep[i];
                        if (repeat == 2) {
                            if (seq[i + 1] > 0) {
                                ans[i] = 6 - seq[i + 1];
                            }
                            else {
                                ans[i] = 0 - seq[i + 1];
                            }
                        }
                        else if (ans[i-1] + 1 < 6) {
                            ans[i] = ans[i-1] + 1;
                        }
                        else {
                            ans[i] = ans[i-1] - 1;
                        }
                    }
                    else {
                        repeat--;
                        if (repeat == 2) {
                            if (seq[i + 1] > 0) {
                                ans[i] = 6 - seq[i + 1];
                            }
                            else {
                                ans[i] = 0 - seq[i + 1];
                            }
                        }
                        else if (ans[i-1] + 1 < 6) {
                            ans[i] = ans[i-1] + 1;
                        }
                        else {
                            ans[i] = ans[i-1] - 1;
                        }
                    }
                    
                }
            }
            
        }
    }
    
    for (int i = 1; i < n; i++) {
        if (key[i] == key[i-1] && ans[i] == ans[i-1]) {
            pos = false;
        }
    }
    
    if (!pos) {
        cout << -1 << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] <<  " ";
        }
        cout << endl;
    }
    
}