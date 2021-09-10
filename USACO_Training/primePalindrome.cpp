/*
 ID: josh.sa1
 TASK: pprime
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long a, b, ans[100000], counter = 0, x, y;

bool isPrime(long long number) {
    for (int i=2; i*i<=number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;
    
    if (isOdd)
        n /= b;
    
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

int main() {
    
    ofstream cout ("pprime.out");
    ifstream cin ("pprime.in");
    
    cin >> a >> b;
    
    int counter = 0;
    long long b1 = b;
    long long j = b;
    
    while (b1 > 0) {
        b1 /= 10;
        counter++;
    }
    
    for (int i = 0; i < counter/2 - 1; i++) {
        j /= 10;
    }
    
    counter = 0;
    for (int i = 1; i <= j; i++) {
        x = createPalindrome(i,10,false);
        if (a <= x && b >= x && isPrime(x)){
            ans[counter] = x;
            counter++;
        }
        
        y = createPalindrome(i,10,true);
        if (a <= y && b >= y && isPrime(y)){
            ans[counter] = y;
            counter++;
        }
    }
    
    sort(ans, ans+counter);
    
    for (int i = 0; i < counter; i++) {
       cout << ans[i] << endl;
    }
        
    
    
    
}