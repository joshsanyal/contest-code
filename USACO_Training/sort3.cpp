/*
 ID: josh.sa1
 TASK: sort3
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

int n, order[1010], ones = 0, twos = 0, threes = 0, ans = 0;

int main() {
    
    ofstream cout ("sort3.out");
    ifstream cin ("sort3.in");
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        if (order[i] == 1) ones++;
        if (order[i] == 2) twos++;
        if (order[i] == 3) threes++;
    }
    
    
    bool onesInPlace = false;
    int place, counter, counter2;
    
    while (!onesInPlace) {
        // Initial Search and Swap
        counter = 0;
        counter2 = 0;
        for (int i = ones; i < n; i++) {
            if (order[i] == 1) {
                counter++;
                if (i >= n-threes) place = 3;
                else place = 2;
                for (int j = 0; j < ones; j++) {
                    if (order[j] == place) {
                        counter2++;
                        int a = order[j];
                        order[j] = order[i];
                        order[i] = a;
                        ans++;
                        break;
                    }
                }
            }
        }
        
        // If no swap, but ones are misplaced, swap
        if (counter != 0 && counter2 == 0) {
            int b = ones;
            while (order[b] != 1) {
                b++;
            }
            
            int c = 0;
            while (order[c] == 1) {
                c++;
            }
            
            int a = order[b];
            order[b] = order[c];
            order[c] = a;
            ans++;
        }
        
        // If done
        else if (counter == 0) {
            onesInPlace = true;
        }
    }
    
    for (int i = ones+twos; i < n; i++) {
        if (order[i] == 2) {
            ans++;
        }
    }
    
    cout << ans << endl;

}