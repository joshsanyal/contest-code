/*
 ID: josh.sa1
 TASK: sprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int firstDigit[4] = {2,3,5,7};
int secondDigit[4] = {1,3,7,9};
int ans[10000], counter = 0;

bool isPrime(long long number) {
    for (int i=2; i*i<number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void gen(long long num, int x) {
    
    if (x == n) {
        ans[counter] = num;
        counter++;
        return;
    }
    
    for (int i = 0; i<4; i++) {
        if (x == 0) {
            if (isPrime(num*10+firstDigit[i])) {
                gen (num*10+firstDigit[i], x+1);
            }
        }
        else {
            if (isPrime(num*10+secondDigit[i])) {
                gen (num*10+secondDigit[i], x+1);
            }
        }
    }
}

int main() {
    
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    
    fin >> n;
    gen(0,0);
    
    for (int i = 0; i < counter; i++) {
        fout << ans[i] << endl;
    }
    
}