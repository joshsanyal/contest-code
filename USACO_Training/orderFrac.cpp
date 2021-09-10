/*
 ID: josh.sa1
 TASK: frac1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct fraction {
    int num;
    int denom;
    long val;
} ;

bool fractioncompare(fraction lhs, fraction rhs) { return lhs.val < rhs.val; }


int n, counter = 0;
fraction frac[25000];

int main() {
    
    ofstream cout ("frac1.out");
    ifstream cin ("frac1.in");
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            bool usable = true;
            for (int k = 0; k < counter; k++) {
                if (frac[k].val == j*1000000/i) {
                    usable = false;
                    break;
                }
            }
            if (usable) {
                frac[counter].num = j;
                frac[counter].denom = i ;
                frac[counter].val = j*1000000/i;
                counter++;
            }
        }
    }
    
    sort(frac, frac+counter, fractioncompare);
    
    for (int i = 0; i < counter; i++) {
        cout << frac[i].num << "/" << frac[i].denom << endl;
    }
    
    
}